#include "rectangle.h"

Rectangle::Rectangle() {}

Rectangle::~Rectangle() noexcept {}

float Rectangle::area() const {
  return 0;
}

float Rectangle::perimeter() const {
  return 0;
}

void Rectangle::paint(QPainter* painter) {
  std::cout << "Rectangle\n";
}