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
  return M_PI * majorAxis_ * minorAxis_;
}

float Ellipse::perimeter() const {
  // Note: there is no easy and accurate way to
  // calculate the perimeter of an ellipse without
  // using infinite sums and integrals, so this is
  // an approximation within 5% of true value so long
  // as a is not 3 times longer than b.
  float a = pow(majorAxis_, 2);
  float b = pow(minorAxis_, 2);
  float radicand = (a + b) / 2;
  return 2 * M_PI * sqrt(radicand);
}

void Ellipse::paint(QPainter* painter) {
  Ellipse* ellipse = (Ellipse*)(shapes.at(5).get());

  painter->setRenderHint(QPainter::Antialiasing, true);
  painter->setPen(ellipse->pen_);
  painter->setBrush(ellipse->pen_.brush());
  painter->drawEllipse(
      QPointF(ellipse->points_[0].x(), ellipse->points_[0].y()), ellipse->majorAxis_,
      ellipse->minorAxis_);
}
