#include "polygon.h"

Polygon::Polygon() {}

Polygon::~Polygon() noexcept {}

float Polygon::area() const {
  return 0;
}

float Polygon::perimeter() const {
  return 0;
}

void Polygon::paint(QPainter* painter) {
  std::cout << "Polygon\n";
}
