#ifndef VIOLET_APP_INFO_H
#define VIOLET_APP_INFO_H

#include <string>
#include <utility>

namespace violet {

class AppInfo final {
public:

  explicit AppInfo(const std::string& name) : name_(name) {};

  explicit AppInfo(std::string&& name) noexcept : name_(std::move(name)) {};

  const std::string& name() const noexcept {
    return name_;
  }

private:

  const std::string name_;

};

}

#endif
