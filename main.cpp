#include <cstdint>
#include <fcntl.h>
#include <fstream>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "proto/demo.pb.h"
#include <google/protobuf/stubs/common.h>
#include <ios>
#include <limits>
#include <sstream>
using namespace google::protobuf::io;
int main(void) {
  // std::fstream input("demo.dem", std::ios::in | std::ios::binary);
  GOOGLE_PROTOBUF_VERSION;
  char *buf = new char[2048];
  int fd = open("demo.dem", O_RDONLY);
  ZeroCopyInputStream *raw = new FileInputStream(fd);
  CodedInputStream *input = new CodedInputStream(raw);
  input->Skip(16);
  uint32_t kind, tick, frame_size;
  input->ReadVarint32(&kind);
  input->ReadVarint32(&tick);
  input->ReadVarint32(&frame_size);
  
  CDemoFileHeader x;
  if (std::numeric_limits<uint32_t>::max() == tick) tick = 0;
  std::cout << kind << " " << tick << " "<< frame_size;
  x.ParseFromCodedStream(input);
  x.PrintDebugString();
}
