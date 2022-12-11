#include "line.h"

Line::Line() {}

Line::~Line() noexcept {}

float Line::area() const {
  return 0;
}

float Line::perimeter() const {
  return 0;
}

void Line::paint(QPainter* painter) {
  std::cout << "Line\n";
}