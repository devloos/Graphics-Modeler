#pragma once

namespace GM {
static const int LINE = 0;
static const int  POLYLINE = 1;
static const int POLYGON = 2;
static const int RECTANGLE = 3;
static const int SQUARE = 4;
static const int ELLIPSE = 5;
static const int CIRCLE = 6;
static const int TEXT = 7;

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