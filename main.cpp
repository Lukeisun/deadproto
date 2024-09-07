#include "Bits.hpp"
#include "Demo.hpp"
#include "gen/citadel_usermessages.pb.h"
#include "gen/demo.pb.h"
#include "gen/netmessages.pb.h"
#include "gen/networkbasetypes.pb.h"
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
// #define FILENAME "test_demo.dem"
#define FILENAME "demo.dem"
using namespace google::protobuf::io;
std::unordered_map<int, int> ubit_map;
class Entry {
public:
  int index;
  std::string table_name;
  std::string key;
  std::vector<uint8_t> value;
  Entry(std::string table_name, int index, std::string key,
        std::vector<uint8_t> value)
      : index(index), table_name(table_name), key(key), value(value){};
};
std::unordered_map<uint32_t, Entry> st_entries;

void parse_string_table(CSVCMsg_CreateStringTable &table) {
  std::cout << table.GetTypeName() << std::endl;
  if (table.name() == "genericprecache")
    return;
  // if (table.name() != "userinfo")
  //   return;
  table.PrintDebugString();
  auto _data = table.string_data();
  std::string data;
  if (table.data_compressed()) {
    snappy::Uncompress(_data.data(), _data.size(), &data);
    assert(data.size() == table.uncompressed_size());
  } else {
    data = _data;
  }
  Bits *bits = new Bits(data.data(), data.size());
  std::vector<std::string> keys{};
  int index = -1;
  if (bits->bits_remaining() == 0)
    return;
  for (auto i = 0; i < table.num_entries(); i++) {
    std::string key = "";
    // Increment index
    if (bits->read_boolean()) {
      index++;
    } else {
      index = bits->readVarInt32() + 1;
    }
    // Has key?
    if (bits->read_boolean()) {
      // Look at history?
      if (bits->read_boolean()) {
        auto pos = bits->read_n_bits(5);
        auto len = bits->read_n_bits(5);
        if (pos >= keys.size()) {
          key += bits->read_string();
        } else {
          auto s = keys[pos];
          auto parsed_string = bits->read_string();
          if (len > s.length()) {
            key += s + parsed_string;
          } else {
            key += (s.substr(0, len)) + parsed_string;
          }
        }
      } else {
        key = bits->read_string();
      }
    } else {
      // need a map of prev keys?
      auto entry = st_entries.at(index);
      key = entry.key;
    }
    if (std::find(keys.begin(), keys.end(), key) != keys.end()) {
      keys.emplace_back(key);
    }
    std::cout << "Key: " << key << std::endl;
    // Has value?
    if (bits->read_boolean()) {
      std::cout << "HAS VALUE" << std::endl;
      uint64_t bit_size = 0;
      bool is_compressed = false;
      if (table.user_data_fixed_size()) {
        bit_size = table.user_data_size_bits();
      } else {
        if ((table.flags() & 0x1) != 0) {
          is_compressed = bits->read_boolean();
        }
        std::cout << "compressed?" << is_compressed << std::endl;
        if (table.using_varint_bitcounts()) {
          auto ubit = bits->read_ubit();
          bit_size = ubit * 8;
        } else {
          bit_size = bits->read_n_bits(17) * 8;
        }
      }
      std::cout << "bitsize " << bit_size << std::endl;
      auto value = bits->read_bits(bit_size);
      auto st_entry = Entry(table.name(), index, key, value);
      st_entries.insert({index, st_entry});
    }
    // delete bits;
  }
}
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
    assert(buf.size() == size);
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
      table.ParseFromArray(buf.data(), size);
      parse_string_table(table);
      break;
    }
    case svc_UpdateStringTable: {
      CSVCMsg_UpdateStringTable table;
      table.ParseFromArray(buf.data(), size);
      // table.PrintDebugString();
      // parse_string_table(table);
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
    const auto frame = demo->get_frame(i);
    auto command = frame.get_command();
    auto buffer = frame.get_buffer();
    auto buf = buffer.data();
    auto frame_size = frame.get_frame_size();
    auto tick = frame.get_tick();
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
      if (tick == 0)
        std::cout << frame << std::endl;
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
  for (auto it = ubit_map.cbegin(); it != ubit_map.cend(); ++it) {
    std::cout << "Ubit: " << it->first << " Count: " << it->second << "\n";
  }
}
