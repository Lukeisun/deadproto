# Compiler
CXX = g++

# Compiler flags
# -fsanitize=address
CXXFLAGS = -std=c++17 -I./proto  -g
# Linker flags
LDFLAGS = -L/usr/lib  -lprotobuf -g -labsl_log_internal_check_op -labsl_log_internal_message -lsnappy

# Source files
SRCS = main.cpp \
       $(wildcard gen/*.pb.cc)

# Object files
OBJS = $(SRCS:.cpp=.o)
OBJS := $(OBJS:.cc=.o)

# Executable name
TARGET = myprogram

# Default target
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
