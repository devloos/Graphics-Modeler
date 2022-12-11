#include "polyline.h"

Polyline::Polyline() {}

Polyline::~Polyline() noexcept {}

float Polyline::area() const {
  return 0;
}

float Polyline::perimeter() const {
  return 0;
}

void Polyline::paint(QPainter* painter) {
  std::cout << "Polyline\n";
}