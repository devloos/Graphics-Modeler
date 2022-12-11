#include "ellipse.h"

Ellipse::Ellipse() {}

Ellipse::~Ellipse() noexcept {}

float Ellipse::area() const {
  return 0;
}

float Ellipse::perimeter() const {
  return 0;
}

void Ellipse::paint(QPainter* painter) {
  std::cout << "Ellipse\n";
}
