#ifndef VIOLET_DETAIL_IMGUI_LAYER_H
#define VIOLET_DETAIL_IMGUI_LAYER_H

#include "../layer.h"
#include "../surface.h"

#include <memory.h>

namespace violet {

class EventQueue;

namespace detail {

class ImGuiLayer final {
public:
  void set_layer(std::unique_ptr<Layer>&& layer) {
    layer_ = std::move(layer);
  }

  std::unique_ptr<Layer>&& remove_layer() {
    std::unique_ptr<Layer> temp{std::move(layer_)};
    return std::move(temp);
  }

  void attach(const Surface& surface);

  void detach();

  void tick(EventQueue& events);

  void render();

private:
  std::unique_ptr<Layer> layer_;
};

} // namespace detail
} // namespace violet

#endif // VIOLET_DETAIL_IMGUI_LAYER_H
