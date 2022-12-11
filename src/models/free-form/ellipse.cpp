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
  Ellipse* ellipse = (Ellipse*)(shapes.at(5).get());

  painter->setRenderHint(QPainter::Antialiasing, true);
  painter->setPen(ellipse->pen_);
  painter->setBrush(ellipse->pen_.brush());
  painter->drawEllipse(
      QPointF(ellipse->points_[0].x(), ellipse->points_[0].y()), ellipse->majorAxis_,
      ellipse->minorAxis_);
}
