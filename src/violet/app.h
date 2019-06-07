#ifndef VIOLET_APP_H
#define VIOLET_APP_H

#define VIOLET_APP(T)\
static T app;\
void violet::App::launch() {\
  violet::constrain(app);\
  app.launch();\
}

namespace violet {

class App final {
public:

  App() = delete;

  static void launch();

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
