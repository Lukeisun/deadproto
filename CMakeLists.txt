cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ProtobufAbseilExample)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Protobuf package
find_package(protobuf REQUIRED HINTS /usr/lib)

message(STATUS ${Protobuf})
# Find Abseil package

# Add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link the executable to Protobuf and all Abseil libraries
message(STATUS "${Protobuf_INCLUDE_DIRS}")
message(STATUS "${Protobuf_LIBRARIES}")
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    ${Protobuf_LIBRARIES}
)
message(STATUS "aaaa")
# Include Protobuf and Abseil directories
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
    ${Protobuf_INCLUDE_DIRS}
)
