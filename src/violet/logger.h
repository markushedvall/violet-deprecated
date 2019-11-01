#ifndef VIOLET_LOGGER_H
#define VIOLET_LOGGER_H

#include <spdlog/logger.h>
#include <string>

namespace violet {

class Logger final {
public:
  explicit Logger(const std::string& name) noexcept;

  Logger(const Logger& other) = delete;

  Logger& operator=(const Logger& other) = delete;

  template<typename... Args>
  void trace(const Args&... args) noexcept {
    logger_.trace(args...);
  }

  template<typename... Args>
  void info(const Args&... args) noexcept {
    logger_.info(args...);
  }

  template<typename... Args>
  void warn(const Args&... args) noexcept {
    logger_.warn(args...);
  }

  template<typename... Args>
  void error(const Args&... args) noexcept {
    logger_.error(args...);
  }

  template<typename... Args>
  void critical(const Args&... args) noexcept {
    logger_.critical(args...);
  }

private:
  spdlog::logger logger_;
};

} // namespace violet

#endif
