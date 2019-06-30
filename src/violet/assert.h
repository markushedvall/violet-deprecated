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

  template<typename T, typename... Args>
  static void is_true(bool condition, const Args&... args) {
    #ifndef NDEBUG
    if (!condition) {
      T::error("Assertion failed: {}", fmt::format(args...));
      std::abort();
    }
    #endif
  }

  template<typename... Args>
  static void is_true(bool condition, const Args&... args) {
    is_true<Log>(condition, args...);
  }

  template<typename... Args>
  static void not_reached(Logger& logger, const Args&... args) {
    #ifndef NDEBUG
    logger.error("Assertion failed: {}", fmt::format(args...));
    std::abort();
    #endif
  }

  template<typename T, typename... Args>
  static void not_reached(const Args&... args) {
    #ifndef NDEBUG
    T::error("Assertion failed: {}", fmt::format(args...));
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
