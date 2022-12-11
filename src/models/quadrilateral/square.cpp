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
  Square* square = (Square*)(shapes.at(4).get());

  painter->setPen(square->pen_);
  painter->setBrush(square->pen_.brush());
  painter->drawRect(
      square->points_[0].x(), square->points_[0].y(), square->length_, square->length_);
}