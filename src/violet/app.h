#ifndef VIOLET_APP_H
#define VIOLET_APP_H

#include <memory>

#include "app_info.h"

#define VIOLET_APP(APP, NAME)\
std::unique_ptr<violet::App> violet::App::create() {\
  return std::unique_ptr<violet::App>(new APP());\
}\
const violet::AppInfo& violet::App::info() {\
  static violet::AppInfo app_info(NAME);\
  return app_info;\
}

namespace violet {

class App {
public:

  virtual ~App() {}

  void run();

  virtual void tick() = 0;

  static std::unique_ptr<App> create();

  static const AppInfo& info();

  static const void terminate() {
    exit(0);
  }

private:

  bool running_;

};

}

#endif
