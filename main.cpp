#include "Bits.hpp"
#include "gen/citadel_clientmessages.pb.h"
#include "gen/citadel_gamemessages.pb.h"
#include "gen/citadel_gcmessages_client.pb.h"
#include "gen/citadel_usermessages.pb.h"
#include "gen/demo.pb.h"
#include "gen/netmessages.pb.h"
#include "gen/networkbasetypes.pb.h"
#include "snappy.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
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
  // Bits *bits = new Bits(data);
  uint64_t temp;
  uint64_t ubit;
  int32_t size;
  std::vector<uint8_t> buf;
  // while (!bits->out_of_bounds()) {
  //   try {
  //     ubit = bits->read_ubit();
  //     size = bits->readVarInt32();
  //     buf = bits->read(size);
  //   } catch (std::out_of_range e) {
  //     break;
  //   }
  //   switch (ubit) {
  //   // case NET_Messages::net_Tick: {
  //   //   CNETMsg_Tick tick;
  //   //   tick.ParseFromArray(buf.data(), size);
  //   //   // tick.PrintDebugString();
  //   //   break;
  //   // }
  //   case svc_PacketEntities: {
  //     CSVCMsg_PacketEntities entities;
  //     // entities.ParseFromArray(buf.data(), size);
  //     // entities.PrintDebugString();
  //     break;
  //   }
  //   case svc_CreateStringTable: {
  //     CSVCMsg_CreateStringTable table;
  //     std::cout << table.GetTypeName() << std::endl;
  //     table.ParseFromArray(buf.data(), size);
  //     // s
  //     if (table.name() == "userinfo") {
  //       auto s_data = table.string_data();
  //       std::string res;
  //       snappy::Uncompress(s_data.data(), s_data.size(), &res);
  //       assert(res.size() == table.uncompressed_size());
  //       // Bits *st_bits = new Bits(res.data());
  //       for (auto i = 0; i < table.num_entries(); i++) {
  //       }
  //
  //       // table.PrintDebugString();
  //       // CMsgPlayerInfo player;
  //       // player.ParseFromArray(res.data(), res.size());
  //       // player.PrintDebugString();
  //     }
  //     break;
  //   }
  //   case k_EUserMsg_ChatMsg: {
  //     CCitadelUserMsg_ChatMsg chat_msg;
  //     std::cout << "Chat Msg: " << std::endl;
  //     chat_msg.ParseFromArray(buf.data(), size);
  //     // chat_msg.PrintDebugString();
  //     break;
  //   }
  //     // case k_eViewedSettings_ChatWheel: {
  //     //   // CCitadelUserMsg_ChatWheel chat_wheel;
  //     //   // std::cout << chat_wheel.GetTypeName() << std::endl;
  //     //   // chat_wheel.ParseFromArray(buf.data(), size);
  //     //   // chat_wheel.PrintDebugString();
  //     //   // break;
  //     // }
  //   default:
  //     // std::cout << "Unknown Ubit" << std::endl;
  //     // std::cout << "Ubit: " << ubit << " Size: " << size << std::endl;
  //     break;
  //   }
  //   ubit_map[ubit] += 1;
  // }
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
  input->SetTotalBytesLimit(file_info.st_size);
  input->Skip(16);
  uint32_t command, tick, frame_size;
  std::unordered_map<int, int> kind_map;
  std::array<uint8_t, 300'000> buf{};
  int prev_size = 0;
  while (input->BytesUntilTotalBytesLimit() != 0) {
    input->ReadVarint32(&command);
    input->ReadVarint32(&tick);
    input->ReadVarint32(&frame_size);
    if (!input->ReadRaw(buf.data(), frame_size)) {
      std::cerr << "error reading to buffer" << std::endl;
      exit(EXIT_FAILURE);
    }
    int32_t msg_type = command & ~EDemoCommands::DEM_IsCompressed;
    bool is_compressed = (command & EDemoCommands::DEM_IsCompressed) ==
                         EDemoCommands::DEM_IsCompressed;
    // std::cout << tick << std::endl;
    if (UINT32_MAX == tick)
      tick = 0;
    if (is_compressed) {
      std::string uncompress;
      snappy::Uncompress(reinterpret_cast<char *>(buf.data()), frame_size,
                         &uncompress);
      std::memcpy(buf.data(), uncompress.data(), uncompress.size());
      command = (command & ~64);
    }
    assert(EDemoCommands_IsValid(command));
    // std::cout << "Command: " << command << " Tick: " << tick
    //           << " Frame Size: " << frame_size << " Compressed? "
    //           << is_compressed << std::endl;
    switch (command) {
    case EDemoCommands::DEM_FileHeader: {
      CDemoFileHeader header;
      std::cout << header.GetTypeName() << std::endl;
      header.ParseFromArray(buf.data(), frame_size);
      header.PrintDebugString();
      break;
    }
    case EDemoCommands::DEM_SignonPacket:
    case EDemoCommands::DEM_Packet: {
      CDemoPacket packet;
      // std::cout << packet.GetTypeName() << std::endl;
      // std::cout << buf.data();
      packet.ParseFromArray(buf.data(), frame_size);
      auto data = packet.data();
      handle_packet(data);
      break;
    }
    case EDemoCommands::DEM_SendTables: {
      CDemoSendTables table;
      table.ParseFromArray(buf.data(), frame_size);
      std::cout << table.GetTypeName() << std::endl;
      // table.PrintDebugString();
    }
    case EDemoCommands::DEM_StringTables: {
      CDemoStringTables st;
      st.ParseFromArray(buf.data(), frame_size);
      // std::cout << st.GetTypeName() << std::endl;
      // st.PrintDebugString();
      break;
    }
    case EDemoCommands::DEM_ClassInfo: {
      CDemoClassInfo class_info;
      class_info.ParseFromArray(buf.data(), frame_size);
      // std::cout << class_info.GetTypeName() << std::endl;
      // class_info.PrintDebugString();
      break;
    }
    default: {
      std::cout << "Unknown Kind" << std::endl;
      break;
    }
    }
    kind_map[command] += 1;
  }
  for (auto it = kind_map.cbegin(); it != kind_map.cend(); ++it) {
    std::cout << "Kind: " << it->first << " Count: " << it->second << "\n";
  }
  // for (auto it = ubit_map.cbegin(); it != ubit_map.cend(); ++it) {
  //   std::cout << "Ubit: " << it->first << " Count: " << it->second << "\n";
  // }
}
