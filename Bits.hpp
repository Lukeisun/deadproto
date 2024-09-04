#include <cassert>
#include <cstdint>
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
  Bits(char *bytes, size_t bytes_len) {
    this->bytes_len = bytes_len;
    this->bytes = bytes;
    this->byte_pos = 0;
    this->bit_pos = 0;
  }
  // TODO: get rid of exception >:(
  uint64_t read_n_bits(int n) {
    uint64_t res = 0;
    for (int i = 0; i < n; i += 1) {
      if (this->out_of_bounds()) {
        throw std::out_of_range("");
      }
      if ((this->bit_pos) >= 8) {
        this->byte_pos++;
        this->bit_pos = 0;
      }
      // get bit
      res |= ((this->bytes[this->byte_pos] >> this->bit_pos) & 1) << i;
      this->bit_pos += 1;
      assert(!(bit_pos > 8));
    }
    return res;
  }
  int32_t readVarInt32() {
    int32_t value = 0;
    int shift = 0;
    uint8_t byte;
    do {
      byte = this->read_n_bits(8);
      value |= (byte & 0x7f) << shift;
      shift += 7;
    } while ((byte & 0x80) != 0);
    return value;
  }
  uint64_t read_ubit() {
    auto res = this->read_n_bits(6);
    auto flag = res & 0x30;
    if (flag == 16) {
      res = (res & 15) | (this->read_n_bits(4) << 4);
    } else if (flag == 32) {
      res = (res & 15) | (this->read_n_bits(8) << 4);
    } else if (flag == 48) {
      res = (res & 15) | (this->read_n_bits(28) << 4);
    }
    return res;
  }
  bool read_boolean() { return this->read_n_bits(1) == 1; }
  std::vector<uint8_t> read(int n) {
    std::vector<uint8_t> data(n);
    for (int i = 0; i < n; i++) {
      data[i] = this->read_n_bits(8);
    }
    return data;
  }
  std::string read_string() {
    std::string str;
    for (int i = 0; i < this->MAX_STR_LEN; i++) {
      const char b = static_cast<char>(this->read_n_bits(8));
      if (b == 0) break;
      str.push_back(b);
    }
    return str;
  }

  bool out_of_bounds() { return this->byte_pos >= this->bytes_len; }
  ~Bits() = default;
};
