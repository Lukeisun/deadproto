#include "Bits.hpp"
#include "gen/citadel_clientmessages.pb.h"
#include "gen/citadel_usermessages.pb.h"
#include "gen/demo.pb.h"
#include "gen/netmessages.pb.h"
#include "snappy.h"
#include <cstdint>
#include <cstdlib>
#include <fcntl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/parse_context.h>
#include <google/protobuf/stubs/common.h>
#include <ostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unordered_map>
#include <vector>
#define FILENAME "test_demo.dem"
// #define FILENAME "demo.dem"
using namespace google::protobuf::io;
enum class Kind {
  CDemoFileHeader = 1,
  CDemoPacket = 7,
};
std::unordered_map<int, int> ubit_map;

void handle_packet(std::string data) {
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

    switch (ubit) {
    case 4: {
      CNETMsg_Tick tick;
      tick.ParseFromArray(buf.data(), size);
      // tick.PrintDebugString();
      break;
    }
    case 55: {
      CSVCMsg_PacketEntities entities;
      entities.ParseFromArray(buf.data(), size);
      entities.PrintDebugString();
      break;
    }
    default:
      std::cout << "Unknown Ubit" << std::endl;
      std::cout << "Ubit: " << ubit << " Size: " << size << std::endl;
      break;
    }
    ubit_map[ubit] += 1;
  }
  delete bits;
}

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
  std::unordered_map<int, int> kind_map;
  while (input->BytesUntilTotalBytesLimit() != 0) {
    input->ReadVarint32(&kind);
    input->ReadVarint32(&tick);
    input->ReadVarint32(&frame_size);
    kind_map[kind] += 1;
    int32_t msg_type = kind & ~EDemoCommands::DEM_IsCompressed;
    bool is_compressed = (kind & EDemoCommands::DEM_IsCompressed) ==
                         EDemoCommands::DEM_IsCompressed;

    if (UINT32_MAX == tick)
      tick = 0;
    std::cout << "Kind: " << kind << " Tick: " << tick
              << " Frame Size: " << frame_size << " Compressed? "
              << is_compressed << std::endl;

    std::vector<uint8_t> buf(frame_size);
    if (!input->ReadRaw(buf.data(), frame_size)) {
      std::cerr << "error reading to buffer" << std::endl;
      exit(EXIT_FAILURE);
    }

    if (is_compressed) {
      size_t res;
      auto x = snappy::GetUncompressedLength(reinterpret_cast<const char *>(buf.data()), buf.size(),
                                          &res);
      std::vector<uint8_t> uncompressed(res);
      snappy::RawUncompress(reinterpret_cast<const char *>(buf.data()),
                            buf.size(),
                            reinterpret_cast<char *>(uncompressed.data()));
      buf.swap(uncompressed);
    }
    switch (kind) {
    case 1: {
      CDemoFileHeader hdr;
      if (!hdr.ParseFromArray(buf.data(), buf.size())) {
        exit(EXIT_FAILURE);
      }
      hdr.PrintDebugString();
      break;
    }
    case static_cast<uint32_t>(Kind::CDemoPacket): {
      CDemoPacket packet;
      packet.ParseFromArray(buf.data(), buf.size());
      auto data = packet.data();
      handle_packet(data);
    }
    case 71: {
      CSVCMsg_ServerInfo server_info;
      server_info.ParseFromArray(buf.data(), buf.size());
      // server_info.PrintDebugString();
      break;
    }

    default: {
      std::cout << "Unknown Kind" << std::endl;
      break;
    }
    }
  }
  for (auto it = kind_map.cbegin(); it != kind_map.cend(); ++it) {
    std::cout << "Kind: " << it->first << " Count: " << it->second << "\n";
  }
  for (auto it = ubit_map.cbegin(); it != ubit_map.cend(); ++it) {
    std::cout << "Ubit: " << it->first << " Count: " << it->second << "\n";
  }
}
