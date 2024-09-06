#include <cassert>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
#pragma once
class Bits {
private:
  char *bytes;
  size_t bytes_len;
  uint8_t bit_pos;
  int byte_pos;
  static constexpr const uint32_t MAX_STR_LEN = 4082;

public:
  Bits(char *bytes, size_t bytes_len);
  ~Bits() = default;
  uint64_t read_n_bits(int n);
  // reaully uint
  int32_t readVarInt32(); 
  uint64_t read_ubit();
  bool read_boolean();
  std::vector<uint8_t> read(int n);
  std::string read_string();

  uint64_t bits_remaining();

  bool out_of_bounds();
};
