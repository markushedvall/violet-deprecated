#ifndef VIOLET_APP_INFO_H
#define VIOLET_APP_INFO_H

#include <string>
#include <utility>

namespace violet {

class AppInfo final {
public:

  explicit AppInfo(const std::string& name) : app_name(name) {};

  explicit AppInfo(std::string&& name) noexcept : app_name(std::move(name)) {};

  const std::string& name() const noexcept {
    return app_name;
  }

private:

  const std::string app_name;

};

}

#endif
