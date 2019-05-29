#ifndef VIOLET_DETAIL_ENGINE_LOG_H
#define VIOLET_DETAIL_ENGINE_LOG_H

#include "../logger.h"

namespace violet {
namespace detail {

class EngineLog final {
public:

  EngineLog() = delete;

  template<typename... Args>
  static void trace(const Args&... args) {
    logger().trace(args...);
  }

  template<typename... Args>
  static void info(const Args&... args) {
    logger().info(args...);
  }

  template<typename... Args>
  static void warn(const Args&... args) {
    logger().warn(args...);
  }

  template<typename... Args>
  static void error(const Args&... args) {
    logger().error(args...);
  }

  template<typename... Args>
  static void critical(const Args&... args) {
    logger().critical(args...);
  }

private:

  static Logger& logger();

};

}
}

#endif
