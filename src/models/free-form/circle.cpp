#include "circle.h"

Circle::Circle() {}

Circle::~Circle() noexcept {}

float Circle::area() const {
  return 0;
}

float Circle::perimeter() const {
  return 0;
}

void Circle::paint(QPainter* painter) {
  std::cout << "Circle\n";
}