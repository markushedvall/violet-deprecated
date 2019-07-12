cmake_minimum_required(VERSION 3.1)
project(Violet CXX)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_SOURCE_DIR}/cmake/cotire.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(violet
  src/violet/entry_point.cpp
  src/violet/app.cpp
  src/violet/logger.cpp
  src/violet/log.cpp
  src/violet/detail/engine_log.cpp
)

set(VIOLET_PCH_DIR ${CMAKE_SOURCE_DIR}/src/violet/detail/pch)

target_include_directories(violet PRIVATE ${VIOLET_PCH_DIR})

set_target_properties(violet PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${VIOLET_PCH_DIR}/pch.h)
cotire(violet)
