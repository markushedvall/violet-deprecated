#ifndef VIOLET_LOGGER_H
#define VIOLET_LOGGER_H

#include <string>
#include <spdlog/logger.h>

namespace violet {

class Logger final {
public:

  explicit Logger(const std::string& name) noexcept;

  Logger(const Logger& other) = delete;

  Logger& operator=(const Logger& other) = delete;

  template<typename... Args>
  void trace(const Args&... args) noexcept {
    logger.trace(args...);
  }

  template<typename... Args>
  void info(const Args&... args) noexcept {
    logger.info(args...);
  }

  template<typename... Args>
  void warn(const Args&... args) noexcept {
    logger.warn(args...);
  }

  template<typename... Args>
  void error(const Args&... args) noexcept {
    logger.error(args...);
  }

  template<typename... Args>
  void critical(const Args&... args) noexcept {
    logger.critical(args...);
  }

private:

  spdlog::logger logger;

};

}

#endif
