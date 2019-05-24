cmake_minimum_required(VERSION 3.1)
project(PackageTest CXX)

set(CMAKE_CXX_STANDARD 11)

# add_definitions("-fconcepts")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(package_test package_test.cpp)
target_link_libraries(package_test ${CONAN_LIBS})
