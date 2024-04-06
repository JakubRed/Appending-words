cmake_minimum_required(VERSION 3.10)
project(Appending-words)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Appending-words src/main.cpp src/LinuxFileWrite.cpp src/WindowsFileWrite.cpp)
