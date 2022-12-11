#include "square.h"

Square::Square() {}

Square::~Square() noexcept {}

float Square::area() const {
  return 0;
}

float Square::perimeter() const {
  return 0;
}

void Square::paint(QPainter* painter) {
  std::cout << "Square\n";
}