#include "Bits.hpp"
#include "Demo.hpp"
#include "gen/citadel_usermessages.pb.h"
#include "gen/demo.pb.h"
#include "gen/netmessages.pb.h"
#include "snappy.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/parse_context.h>
#include <google/protobuf/stubs/common.h>
#include <istream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <sys/stat.h>
#include <sys/types.h>
#include <unordered_map>
#include <vector>
#define FILENAME "test_demo.dem"
// #define FILENAME "demo.dem"
using namespace google::protobuf::io;
std::unordered_map<int, int> ubit_map;

void handle_packet(std::string data) {
  Bits *bits = new Bits(data.data(), data.size());
  uint64_t temp;
  uint64_t ubit;
  int32_t size;
  std::vector<uint8_t> buf;
  while (bits->bits_remaining() > 8) {
    ubit = bits->read_ubit();
    size = bits->readVarInt32();
    buf = bits->read(size);
    switch (ubit) {
    // case NET_Messages::net_Tick: {
    //   CNETMsg_Tick tick;
    //   tick.ParseFromArray(buf.data(), size);
    //   // tick.PrintDebugString();
    //   break;
    // }
    case svc_PacketEntities: {
      CSVCMsg_PacketEntities entities;
      // entities.ParseFromArray(buf.data(), size);
      // entities.PrintDebugString();
      break;
    }
    case svc_CreateStringTable: {
      CSVCMsg_CreateStringTable table;
      std::cout << table.GetTypeName() << std::endl;
      table.ParseFromArray(buf.data(), size);
      if (table.name() == "userinfo") {
        auto s_data = table.string_data();
        std::string st_data;
        snappy::Uncompress(s_data.data(), s_data.size(), &st_data);
        assert(st_data.size() == table.uncompressed_size());
        Bits *st_bits = new Bits(st_data.data(), st_data.size());
        std::vector<std::string> keys{};
        int index = -1;
        for (auto i = 0; i < table.num_entries(); i++) {
          std::string key;
          // Increment index
          if (st_bits->read_boolean()) {
            index++;
          } else {
            index += st_bits->readVarInt32() + 1;
          }
          // Has key?
          if (st_bits->read_boolean()) {
            // Look at history?
            if (st_bits->read_boolean()) {
              auto pos = st_bits->read_n_bits(5);
              auto len = st_bits->read_n_bits(5);
              if (pos >= keys.size()) {
                key.append(st_bits->read_string());
              } else {
                auto s = keys[pos];
                if (len > s.length()) {
                  key += s + st_bits->read_string();
                } else {
                  // key += (s.substr(0, len)) + st_bits->read_string();
                  key +=  st_bits->read_string();
                }
              }
            } else {
              // readstring
              auto key = st_bits->read_string();
            }
          } else {
            // need a map of prev keys?
            key = "";
          }
          std::cout << "Key: " << key << std::endl;
          // Has value?
          if (st_bits->read_boolean()) {
            uint32_t bit_size = 0;
            bool is_compressed = false;
            if (table.user_data_fixed_size()) {
              bit_size = table.user_data_size();
            } else {
              if ((table.flags() & 0x1) != 0) {
                is_compressed = st_bits->read_boolean();
              }
              if (table.using_varint_bitcounts()) {
                bit_size = st_bits->read_ubit() * 8;
              } else {
                bit_size = st_bits->read_n_bits(17) * 8;
              }
            }
            std::cout << "Value: " << st_bits->read_n_bits(bit_size)
                      << std::endl;
          }
        }
        table.PrintDebugString();
        // CMsgPlayerInfo player;
        // player.ParseFromArray(res.data(), res.size());
        // player.PrintDebugString();
      }
      break;
    }
    case k_EUserMsg_ChatMsg: {
      CCitadelUserMsg_ChatMsg chat_msg;
      std::cout << "Chat Msg: " << std::endl;
      chat_msg.ParseFromArray(buf.data(), size);
      // chat_msg.PrintDebugString();
      break;
    }
      // case k_eViewedSettings_ChatWheel: {
      //   // CCitadelUserMsg_ChatWheel chat_wheel;
      //   // std::cout << chat_wheel.GetTypeName() << std::endl;
      //   // chat_wheel.ParseFromArray(buf.data(), size);
      //   // chat_wheel.PrintDebugString();
      //   // break;
      // }
    default:
      // std::cout << "Unknown Ubit" << std::endl;
      // std::cout << "Ubit: " << ubit << " Size: " << size << std::endl;
      break;
    }
    ubit_map[ubit] += 1;
  }
  // delete bits;
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
  Demo *demo = new Demo(*input, file_info.st_size);
  std::cout << demo->get_total_len() << std::endl;
  std::cout << demo->get_frame(2) << std::endl;
  CDemoFileHeader packet;
  packet.ParseFromArray(demo->get_frame(0).get_buffer().data(),
                        demo->get_frame(0).get_frame_size());
  packet.PrintDebugString();
  std::unordered_map<std::string, int> kind_map;
  for (int i = 0; i < demo->get_total_len(); i++) {
    auto frame = demo->get_frame(i);
    auto command = frame.get_command();
    auto buffer = frame.get_buffer();
    auto buf = buffer.data();
    auto frame_size = frame.get_frame_size();
    kind_map[frame.get_command_str()]++;
    switch (command) {
    case EDemoCommands::DEM_FileHeader: {
      CDemoFileHeader header;
      // std::cout << header.GetTypeName() << std::endl;
      header.ParseFromArray(buf, frame_size);
      // header.PrintDebugString();
      break;
    }
    case EDemoCommands::DEM_SignonPacket:
    case EDemoCommands::DEM_Packet: {
      CDemoPacket packet;
      // std::cout << packet.GetTypeName() << std::endl;
      packet.ParseFromArray(buf, frame_size);
      auto data = packet.data();
      handle_packet(data);
      break;
    }
    case EDemoCommands::DEM_SendTables: {
      CDemoSendTables table;
      table.ParseFromArray(buf, frame_size);
      // std::cout << table.GetTypeName() << std::endl;
      // table.PrintDebugString();
    }
    case EDemoCommands::DEM_StringTables: {
      CDemoStringTables st;
      st.ParseFromArray(buf, frame_size);
      // std::cout << st.GetTypeName() << std::endl;
      // st.PrintDebugString();
      break;
    }
    case EDemoCommands::DEM_ClassInfo: {
      CDemoClassInfo class_info;
      class_info.ParseFromArray(buf, frame_size);
      // std::cout << class_info.GetTypeName() << std::endl;
      // class_info.PrintDebugString();
      break;
    }
    default: {
      // std::cout << "Unknown Kind" << std::endl;
      break;
    }
    }
  }
  for (auto it = kind_map.cbegin(); it != kind_map.cend(); ++it) {
    std::cout << "Kind: " << it->first << " Count: " << it->second << "\n";
  }
  // for (auto it = ubit_map.cbegin(); it != ubit_map.cend(); ++it) {
  //   std::cout << "Ubit: " << it->first << " Count: " << it->second << "\n";
  // }
}
