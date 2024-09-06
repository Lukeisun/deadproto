#include "Demo.hpp"
#include <stdexcept>

Demo::Demo(google::protobuf::io::CodedInputStream &input, int limit) {
  input.SetTotalBytesLimit(limit);
  input.Skip(16);
  uint32_t command, tick, frame_size;
  while (input.BytesUntilTotalBytesLimit() != 0) {
    input.ReadVarint32(&command);
    input.ReadVarint32(&tick);
    input.ReadVarint32(&frame_size);
    std::vector<uint8_t> buf;
    buf.resize(frame_size);
    if (!input.ReadRaw(buf.data(), frame_size)) {
      std::cerr << "error reading to buffer" << std::endl;
      exit(EXIT_FAILURE);
    }
    bool is_compressed = (command & EDemoCommands::DEM_IsCompressed) ==
                         EDemoCommands::DEM_IsCompressed;
    if (is_compressed) {
      size_t uncompressed_size;
      const char *char_buf = reinterpret_cast<const char *>(buf.data());
      snappy::GetUncompressedLength(char_buf, frame_size, &uncompressed_size);
      std::vector<uint8_t> uncompressed_buf;
      uncompressed_buf.resize(uncompressed_size);
      snappy::RawUncompress(char_buf, frame_size,
                            reinterpret_cast<char *>(uncompressed_buf.data()));
      buf.swap(uncompressed_buf);
      frame_size = uncompressed_size;
      command = (command & ~64);
    }
    assert(EDemoCommands_IsValid(command));
    if (tick == UINT32_MAX) tick = 0;
    this->commands.emplace_back(command);
    this->ticks.emplace_back(tick);
    this->frame_sizes.emplace_back(frame_size);
    this->buffers.emplace_back(std::move(buf));
    this->total_len++;
  }
}
uint32_t Demo::get_total_len() { return this->total_len; }

Frame Demo::get_frame(size_t idx) {
  if (idx >= total_len) {
    throw std::out_of_range("Index greater than length of array");
  }
  return Frame(this->commands[idx], this->ticks[idx], this->frame_sizes[idx],
               buffers[idx]);
}
uint32_t Frame::get_command() const { return this->command; }
std::string Frame::get_command_str() const {
  return EDemoCommands_Name(this->command);
}
uint32_t Frame::get_tick() const { return this->tick; }
uint32_t Frame::get_frame_size() const { return this->frame_size; };
std::vector<uint8_t> Frame::get_buffer() const { return this->buffer; };
