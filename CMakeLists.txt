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
  src/violet/detail/platform/desktop/desktop_surface.cpp
  src/violet/detail/imgui_impl.cpp
  src/violet/detail/imgui_layer.cpp
  ${CONAN_SRC_DIRS_IMGUI}/bindings/imgui_impl_glfw.cpp
  ${CONAN_SRC_DIRS_IMGUI}/bindings/imgui_impl_opengl3.cpp
)

# Do not include OpenGl through GLFW
target_compile_definitions(violet PUBLIC GLFW_INCLUDE_NONE IMGUI_IMPL_OPENGL_LOADER_GLAD)

set(VIOLET_PCH_DIR ${CMAKE_SOURCE_DIR}/src/violet/detail/pch)

target_include_directories(violet PRIVATE ${VIOLET_PCH_DIR} ${CONAN_SRC_DIRS_IMGUI}/bindings)

set_target_properties(violet PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${VIOLET_PCH_DIR}/pch.h)
cotire(violet)
