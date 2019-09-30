#ifndef VIOLET_APP_H
#define VIOLET_APP_H

#include <memory>

#include "app_info.h"
#include "surface.h"
#include "layer.h"
#include "layer_stack.h"

#define VIOLET_APP(APP, NAME)\
std::unique_ptr<violet::App> violet::App::create() {\
  return std::unique_ptr<violet::App>(new APP());\
}\
const violet::AppInfo& violet::App::info() {\
  static violet::AppInfo app_info(NAME);\
  return app_info;\
}

namespace violet {

class EventQueue;

class App : public Layer {
public:

  void run();

  void push_layer(Layer* layer);

  static std::unique_ptr<App> create();

  static const AppInfo& info();

  static const void terminate() {
    terminate_ = true;
  }

private:

  void poll_events(EventQueue& events);

  static volatile bool terminate_;
  bool running_;
  Surface surface_;
  LayerStack layer_stack_;

};

}

#endif
