cmake_minimum_required(VERSION 3.1)
project(Violet CXX)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_SOURCE_DIR}/cmake/cotire.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(VIOLET_HEADERS
  ${CMAKE_SOURCE_DIR}/src/violet.h
  ${CMAKE_SOURCE_DIR}/src/violet/app_info.h
  ${CMAKE_SOURCE_DIR}/src/violet/app.h
  ${CMAKE_SOURCE_DIR}/src/violet/assert.h
  ${CMAKE_SOURCE_DIR}/src/violet/entry_point.h
  ${CMAKE_SOURCE_DIR}/src/violet/event_queue.h
  ${CMAKE_SOURCE_DIR}/src/violet/event.h
  ${CMAKE_SOURCE_DIR}/src/violet/layer_stack.h
  ${CMAKE_SOURCE_DIR}/src/violet/layer.h
  ${CMAKE_SOURCE_DIR}/src/violet/log.h
  ${CMAKE_SOURCE_DIR}/src/violet/logger.h
  ${CMAKE_SOURCE_DIR}/src/violet/surface.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/engine_log.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/event_category.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/imgui_impl.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/imgui_layer.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/events/app_events.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/events/key_events.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/events/mouse_events.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/platform/desktop/desktop_surface.h
  ${CMAKE_SOURCE_DIR}/src/violet/detail/util/range.h
)

set(VIOLET_SOURCES
  ${CMAKE_SOURCE_DIR}/src/violet/app.cpp
  ${CMAKE_SOURCE_DIR}/src/violet/entry_point.cpp
  ${CMAKE_SOURCE_DIR}/src/violet/log.cpp
  ${CMAKE_SOURCE_DIR}/src/violet/logger.cpp
  ${CMAKE_SOURCE_DIR}/src/violet/detail/engine_log.cpp
  ${CMAKE_SOURCE_DIR}/src/violet/detail/imgui_impl.cpp
  ${CMAKE_SOURCE_DIR}/src/violet/detail/imgui_layer.cpp
  ${CMAKE_SOURCE_DIR}/src/violet/detail/platform/desktop/desktop_surface.cpp
)

add_library(violet
  ${VIOLET_SOURCES}
  ${VIOLET_HEADERS}
  ${CONAN_SRC_DIRS_IMGUI}/bindings/imgui_impl_glfw.cpp
  ${CONAN_SRC_DIRS_IMGUI}/bindings/imgui_impl_opengl3.cpp
)

# Do not include OpenGl through GLFW
target_compile_definitions(violet PUBLIC GLFW_INCLUDE_NONE IMGUI_IMPL_OPENGL_LOADER_GLAD)

set(VIOLET_PCH_DIR ${CMAKE_SOURCE_DIR}/src/violet/detail/pch)

target_include_directories(violet PRIVATE ${VIOLET_PCH_DIR} ${CONAN_SRC_DIRS_IMGUI}/bindings)

set_target_properties(violet PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${VIOLET_PCH_DIR}/pch.h)
cotire(violet)

find_program(CLANG_FORMAT NAMES clang-format)
if(CLANG_FORMAT)
  add_custom_target(format
    COMMAND ${CLANG_FORMAT} -i ${VIOLET_SOURCES} ${VIOLET_HEADERS}
  )
endif()
