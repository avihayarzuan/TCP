cmake_minimum_required(VERSION 3.8)
project(TCPserver)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp
                Server.cpp
                Server.h
                ReadPort.h
                ReadPort.cpp)
add_executable(TCPserver ${SOURCE_FILES})