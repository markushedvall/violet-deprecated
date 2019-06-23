#ifndef VIOLET_APP_H
#define VIOLET_APP_H

#include "app_info.h"

#define VIOLET_APP(APP, NAME)\
static APP app;\
static violet::AppInfo app_info(NAME);\
void violet::App::run() {\
  violet::constrain(app);\
  app.run();\
}\
\
const violet::AppInfo& violet::App::info() {\
  return app_info;\
}

namespace violet {

class App final {
public:

  App() = delete;

  static void run();

  static const AppInfo& info();

};

#ifdef __cpp_concepts

template<typename T>
concept Launchable = requires(T a) {
  {a.launch()} -> void;
};

template<typename T>
  requires Launchable<T>
constexpr void constrain(T) {}

#else

template<typename T>
constexpr void constrain(T) {}

#endif

}

#endif
