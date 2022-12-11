#include "circle.h"

Circle::Circle() {}

Circle::~Circle() noexcept {}

void Circle::setRadius(const int &radius) {
  radius_ = radius;
}

int Circle::getRadius() const {
  return radius_;
}

float Circle::area() const {
  return 0;
}

float Circle::perimeter() const {
  return 0;
}

void Circle::paint(QPainter* painter) {
  std::cout << "Circle\n";
}