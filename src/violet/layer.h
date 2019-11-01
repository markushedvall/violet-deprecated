#ifndef VIOLET_LAYER_H
#define VIOLET_LAYER_H

namespace violet {

class EventQueue;

class Layer {
public:
  virtual ~Layer() {}

  virtual void attach() {}

  virtual void detach() {}

  virtual void tick(EventQueue& events) {}

  virtual void render() {}
};

} // namespace violet

#endif
