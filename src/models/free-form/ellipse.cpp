#include "ellipse.h"

Ellipse::Ellipse() {}

Ellipse::~Ellipse() noexcept {}

void Ellipse::setMajorAxis(const int &majorAxis) {
  majorAxis_ = majorAxis;
}

int Ellipse::getMajorAxis() const {
  return majorAxis_;
}

void Ellipse::setMinorAxis(const int &minorAxis) {
  minorAxis_ = minorAxis;
}

int Ellipse::getMinorAxis() const {
  return minorAxis_;
}

float Ellipse::area() const {
  return 0;
}

float Ellipse::perimeter() const {
  return 0;
}

void Ellipse::paint(QPainter* painter) {
  std::cout << "Ellipse\n";
}
