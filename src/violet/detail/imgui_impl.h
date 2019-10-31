#ifndef VIOLET_DETAIL_IMGUI_IMPL_H
#define VIOLET_DETAIL_IMGUI_IMPL_H

#include "../surface.h"

struct ImDrawData;

namespace violet {
namespace detail {

class ImGuiImpl final {
public:
  ImGuiImpl() = delete;

  static void init(const Surface& surface);

  static void shutdown();

  static void new_frame();

  static void render(ImDrawData* draw_data);
};

} // namespace detail
} // namespace violet

#endif // VIOLET_DETAIL_IMGUI_LAYER_H
