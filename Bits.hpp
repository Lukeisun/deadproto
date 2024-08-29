#include <cstdint>
#include <string>
#include <vector>
#pragma once
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
