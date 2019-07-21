#ifndef VIOLET_ENGINE_ASSERT_H
#define VIOLET_ENGINE_ASSERT_H

#include <cstdlib>

#include <fmt/format.h>

#include "logger.h"
#include "log.h"

namespace violet {

class Assert final {
public:

  template<typename... Args>
  static void is_true(Logger& logger, bool condition, const Args&... args) {
    #ifndef NDEBUG
    if (!condition) {
      logger.error("Assertion failed: {}", fmt::format(args...));
      std::abort();
    }
    #endif
  }

  template<typename L, typename... Args>
  static void is_true(bool condition, const Args&... args) {
    #ifndef NDEBUG
    if (!condition) {
      L::error("Assertion failed: {}", fmt::format(args...));
      std::abort();
    }
    #endif
  }

  template<typename... Args>
  static void is_true(bool condition, const Args&... args) {
    is_true<Log>(condition, args...);
  }

  template<typename T, typename... Args>
  static void not_null(Logger& logger, const T* ptr, const Args&... args) {
    #ifndef NDEBUG
    if (ptr == nullptr) {
      logger.error("Assertion failed: {}", fmt::format(args...));
      std::abort();
    }
    #endif
  }

  template<typename L, typename T, typename... Args>
  static void not_null(const T* ptr, const Args&... args) {
    #ifndef NDEBUG
    if (ptr == nullptr) {
      L::error("Assertion failed: {}", fmt::format(args...));
      std::abort();
    }
    #endif
  }

  template<typename T, typename... Args>
  static void not_null(const T* ptr, const Args&... args) {
    not_null<Log>(ptr, args...);
  }

  template<typename... Args>
  static void not_reached(Logger& logger, const Args&... args) {
    #ifndef NDEBUG
    logger.error("Assertion failed: {}", fmt::format(args...));
    std::abort();
    #endif
  }

  template<typename L, typename... Args>
  static void not_reached(const Args&... args) {
    #ifndef NDEBUG
    L::error("Assertion failed: {}", fmt::format(args...));
    std::abort();
    #endif
  }

  template<typename... Args>
  static void not_reached(const Args&... args) {
    not_reached<Log>(args...);
  }

};

}

#endif
