#include "proto/citadel_clientmessages.pb.h"
#include "proto/citadel_usermessages.pb.h"
#include "proto/demo.pb.h"
#include "proto/netmessages.pb.h"
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <fcntl.h>
#include <fstream>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/parse_context.h>
#include <google/protobuf/stubs/common.h>
#include <ios>
#include <limits>
#include <ostream>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unordered_map>
#define FILENAME "test_demo.dem"
// #define FILENAME "demo.dem"
using namespace google::protobuf::io;
enum class Kind {
  CDemoFileHeader = 1,
  CDemoPacket = 7,
};
class Bits {
public:
  std::vector<bool> bits;
  int curr_pos;
  Bits(std::string data) {
    std::vector<bool> bits;
    bits.reserve(data.size() * 8); // Reserve space for efficiency
    for (auto c : data) {
      for (int i = 0; i < 8; i++) {
        bits.push_back((c >> i) & 1);
      }
    }
    this->bits = bits;
    this->curr_pos = 0;
  }
  uint64_t read_n_bits(int n) {
    int new_pos = n + this->curr_pos;
    if (new_pos > bits.size()) {
      return 0;
    }
    auto res = this->to_number(n);
    this->curr_pos = new_pos;
    return res;
  }
  uint64_t to_number(int n) {
    uint64_t result = 0;
    for (int i = 0; i < n; i++) {
      result |= (this->bits[i + this->curr_pos] ? 1 : 0) << i;
    }
    return result;
  }
  int32_t readVarInt32() {
    int32_t value = 0;
    int shift = 0;
    uint8_t byte;
    // if (this->curr_pos % 8 == 0)
    //   this->curr_pos += (this->curr_pos % 8);
    do {
      byte = this->read_n_bits(8);
      value |= (byte & 0x7f) << shift;
      shift += 7;
    } while ((byte & 0x80) != 0);
    return value;
  }
  std::vector<uint8_t> read(int n) {
    std::vector<uint8_t> data(n);
    for (int i = 0; i < n; i++) {
      data[i] = this->read_n_bits(8);
    }
    return data;
  }

  bool out_of_bounds() { return this->curr_pos > bits.size(); }
  ~Bits() = default;
};

int main(void) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  int fd = open(FILENAME, O_RDONLY);
  if (fd == -1)
    exit(EXIT_FAILURE);
  struct stat file_info;
  stat(FILENAME, &file_info);
  std::cout << file_info.st_size << std::endl;
  ZeroCopyInputStream *raw = new FileInputStream(fd);
  CodedInputStream *input = new CodedInputStream(raw);
  input->SetTotalBytesLimit(file_info.st_size);
  input->Skip(16);
  uint32_t kind, tick, frame_size;
  // const char *text = "/***********************/\n"
  //                    "*    FRAME INFO         *";
  std::unordered_map<int, int> map;
  while (input->BytesUntilTotalBytesLimit() != 0 && frame_size != UINT32_MAX) {
    input->ReadVarint32(&kind);
    input->ReadVarint32(&tick);
    input->ReadVarint32(&frame_size);
    map[kind] += 1;
    int32_t msg_type = kind & ~EDemoCommands::DEM_IsCompressed;
    bool is_compressed = (kind & EDemoCommands::DEM_IsCompressed) ==
                         EDemoCommands::DEM_IsCompressed;
    if (UINT32_MAX == tick)
      tick = 0;
    // std::cout << text << std::endl;
    std::cout << "Kind: " << kind << " Tick: " << tick
              << " Frame Size: " << frame_size << " Compressed? "
              << is_compressed << std::endl;
    // std::cout << input->BytesUntilTotalBytesLimit() << " " << UINT32_MAX << "
    // "
    //           << file_info.st_size << std::endl;

    auto buf = new char[frame_size];
    if (!input->ReadRaw(buf, frame_size)) {
      std::cerr << "error reading to buffer" << std::endl;
      exit(EXIT_FAILURE);
    }
    switch (kind) {
    case 1: {
      CDemoFileHeader hdr;
      if (!hdr.ParseFromArray(buf, frame_size)) {
        exit(EXIT_FAILURE);
      }
      hdr.PrintDebugString();
      break;
    }
    case static_cast<uint32_t>(Kind::CDemoPacket): {
      CDemoPacket packet;
      packet.ParseFromArray(buf, frame_size);
      packet.PrintDebugString();
      auto data = packet.data();
      Bits *bits = new Bits(data);
      while (!bits->out_of_bounds()) {
        uint64_t ubit;
        uint64_t temp = bits->read_n_bits(6);
        auto flag = temp & 0x30;
        if (flag == 16) {
          temp = (temp & 15) | (bits->read_n_bits(4) << 4);
        } else if (flag == 32) {
          temp = (temp & 15) | (bits->read_n_bits(8) << 4);
        } else if (flag == 48) {
          temp = (temp & 15) | (bits->read_n_bits(28) << 4);
        }
        if (temp == 0)
          break;
        ubit = temp;
        auto size = bits->readVarInt32();
        auto buf = bits->read(size);

        // if (!SVC_Messages_IsValid(ubit)) {
        //     std::cerr << "Not valid svc_message enum value " << ubit <<
        //     std::endl; exit(EXIT_FAILURE);
        //   }
        switch (ubit) {
        case 4: {
          CNETMsg_Tick tick;
          tick.ParseFromArray(buf.data(), size);
          tick.PrintDebugString();
          break;
        }
        case 55: {
          CSVCMsg_PacketEntities entities;
          entities.ParseFromArray(buf.data(), size);
          entities.PrintDebugString();
          break;
        }
        default:
          break;
        }
        std::cout << "Ubit: " << ubit << " Size: " << size << std::endl;
      }
      delete bits;
    }

    default: {
      std::cout << "Unknown Kind" << std::endl;
      break;
    }
    }
    delete[] buf;
  }
  for (auto it = map.cbegin(); it != map.cend(); ++it) {
    std::cout << "Kind: " << it->first << " Count: " << it->second << "\n";
  }
}
