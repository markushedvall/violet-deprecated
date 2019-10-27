#ifndef VIOLET_DETAIL_DESKTOP_SURFACE_H
#define VIOLET_DETAIL_DESKTOP_SURFACE_H

#include <memory>
#include <vector>

#include "../../../event.h"

struct GLFWwindow;

namespace violet {

class EventQueue;

namespace detail {

class DesktopSurface final {
public:
  friend class ImGuiImpl;

  DesktopSurface() noexcept;

  void poll_events(EventQueue& events) noexcept;

  void swap_buffers() const noexcept;

private:

  class GlfwWindowDeleter final {
  public:
    void operator()(GLFWwindow* window);
  };

  using GlfwWindowPtr = std::unique_ptr<GLFWwindow, GlfwWindowDeleter>;

  static GlfwWindowPtr create_window() noexcept;

  void set_vsync(bool enabled) const noexcept;

  GlfwWindowPtr window_;

  std::vector<Event> event_buffer_;

};

}
}

#endif
