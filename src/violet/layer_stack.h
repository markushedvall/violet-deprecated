#ifndef VIOLET_LAYER_STACK_H
#define VIOLET_LAYER_STACK_H

#include <vector>

#include "layer.h"

namespace violet {

class LayerStack final {
public:
  using Iterator = std::vector<std::unique_ptr<Layer>>::iterator;

  ~LayerStack() {
    for (auto&& layer : layers_) {
      layer->detach();
    }
  }

  void push(Layer* layer) {
    layers_.push_back(std::unique_ptr<Layer>(layer));
    layer->attach();
  }

  Iterator begin() noexcept {
    return layers_.begin();
  }

  Iterator end() noexcept {
    return layers_.end();
  }

private:
  std::vector<std::unique_ptr<Layer>> layers_;
};

} // namespace violet

#endif
