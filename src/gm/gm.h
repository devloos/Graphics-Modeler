#pragma once

namespace GM {
enum struct ShapeType {
  Line = 0,
  Polyline,
  Polygon,
  Rectangle,
  Square,
  Ellipse,
  Circle,
  Text
};

namespace Window {
static const int WIDTH = 640;
static const int HEIGHT = 480;
}  // namespace Window
}  // namespace GM