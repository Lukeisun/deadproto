#include "gen/demo.pb.h"
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/message.h>
#include <snappy.h>
#include <vector>
class Frame {
private:
  uint32_t command;
  uint32_t tick;
  uint32_t frame_size;
  std::vector<uint8_t> &buffer;

public:
  Frame(uint32_t command, uint32_t tick, uint32_t frame_size,
        std::vector<uint8_t> &buffer)
      : command(command), tick(tick), frame_size(frame_size), buffer(buffer){};
  uint32_t get_command() const;
  std::string get_command_str() const;
  uint32_t get_tick() const;
  uint32_t get_frame_size() const;
  std::vector<uint8_t> get_buffer() const;
  friend std::ostream &operator<<(std::ostream &out, Frame &data);
};
class Demo {
private:
  // TODO: test AoS vs SoA versions
  std::vector<uint32_t> commands;
  std::vector<uint32_t> ticks;
  std::vector<uint32_t> frame_sizes;
  std::vector<std::vector<uint8_t>> buffers;
  uint32_t total_len;

public:
  Demo(google::protobuf::io::CodedInputStream &input, int limit);
  Frame get_frame(size_t idx);
  uint32_t get_total_len();
};

// Implementation of overloaded << operator for Frame
inline std::ostream &operator<<(std::ostream &out, const Frame &data) {
  out << "Command: " << data.get_command_str() << " Tick: " << data.get_tick()
      << " Frame Size: " << data.get_frame_size() << std::endl;
  out << "Buffer: " << std::endl;
  // for (auto c : data.get_buffer()) {
  //   out << c;
  // }
  out << std::endl << "END" << std::endl;
  return out;
};
