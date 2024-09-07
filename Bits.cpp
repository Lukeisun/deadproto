#include "Bits.hpp"
#include <cmath>
#include <cstdlib>
Bits::Bits(char *bytes, size_t bytes_len) {
  this->bytes_len = bytes_len;
  this->bytes = bytes;
  this->byte_pos = 0;
  this->bit_pos = 0;
}
uint64_t Bits::read_n_bits(int n) {
  uint64_t res = 0;
  for (int i = 0; i < n; i += 1) {
    if (this->out_of_bounds()) {
      throw std::out_of_range("");
    }
    res |= ((this->bytes[this->byte_pos] >> this->bit_pos) & 1) << i;
    this->bit_pos += 1;
    assert(!(bit_pos > 8));
    if ((this->bit_pos) >= 8) {
      this->byte_pos++;
      this->bit_pos = 0;
    }
  }
  return res;
}
int32_t Bits::readVarInt32() {
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
uint64_t Bits::read_ubit() {
  auto res = this->read_n_bits(6);
  switch (res & 48) {
  case 16:
    res = (res & 15) | (this->read_n_bits(4) << 4);
    break;
  case 32:
    res = (res & 15) | (this->read_n_bits(8) << 4);
    break;
  case 48:
    res = (res & 15) | (this->read_n_bits(28) << 4);
    break;
  }
  return res;
}
bool Bits::read_boolean() { return this->read_n_bits(1) == 1; }

std::vector<uint8_t> Bits::read(int n) {
  std::vector<uint8_t> data(n);
  for (int i = 0; i < n; i++) {
    data[i] = static_cast<uint8_t>(this->read_n_bits(8));
  }
  return data;
}
std::vector<uint8_t> Bits::read_bits(int n) {
  std::vector<uint8_t> data(ceil(n/8.0));
  int temp = n;
  for (int i = 0; i < ceil(n/8.0); i++) {
    auto bit_size = (temp % 8 == 0) ? 8 : (temp%8);
    data[i] = static_cast<uint8_t>(this->read_n_bits(bit_size));
    temp -= bit_size;
  }
  return data;
}
std::string Bits::read_string() {
  std::string str;
  for (int i = 0; i < this->MAX_STR_LEN; i++) {
    const char b = static_cast<char>(this->read_n_bits(8));
    // std::cout << "t: " << +b << std::endl;
    if (b == 0)
      break;
    str.push_back(b);
  }
  return str;
}

uint64_t Bits::bits_remaining() {
  return (bytes_len * 8) - (byte_pos * 8) - bit_pos;
}

bool Bits::out_of_bounds() { return this->byte_pos >= this->bytes_len; }
