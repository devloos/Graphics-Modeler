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
  Circle* circle = (Circle*)(shapes.at(6).get());

  painter->setRenderHint(QPainter::Antialiasing, true);
  painter->setPen(circle->pen_);
  painter->setBrush(circle->pen_.brush());
  painter->drawEllipse(
      QPointF(circle->points_[0].x(), circle->points_[0].y()), circle->radius_,
      circle->radius_);
}