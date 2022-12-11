#include "square.h"

Square::Square() {}

Square::~Square() noexcept {}

void Square::setLength(const int &length) {
  length_ = length;
}

int Square::getLength() const {
  return length_;
}

float Square::area() const {
  return 0;
}

float Square::perimeter() const {
  return 0;
}

void Square::paint(QPainter* painter) {
  std::cout << "Square\n";
}