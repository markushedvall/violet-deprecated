cmake_minimum_required(VERSION 3.1)
project(Violet CXX)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(violet
  src/violet/entry_point.cpp
  src/violet/logger.cpp
  src/violet/log.cpp
  src/violet/detail/engine_log.cpp
)
