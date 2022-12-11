#include "rectangle.h"

Rectangle::Rectangle() {}

Rectangle::~Rectangle() noexcept {}

void Rectangle::setLength(const int &length) {
  length_ = length;
}

int Rectangle::getLength() const {
  return length_;
}

void Rectangle::setWidth(const int &width) {
  width_ = width;
}

int Rectangle::getWidth() const {
  return width_;
}

float Rectangle::area() const {
  return 0;
}

float Rectangle::perimeter() const {
  return 0;
}

void Rectangle::paint(QPainter* painter) {
  std::cout << "Rectangle\n";
  Rectangle* rec = (Rectangle*)(shapes.at(3).get());

  painter->setPen(rec->pen_);
  painter->setBrush(rec->pen_.brush());
  painter->drawRect(rec->points_[0].x(), rec->points_[0].y(), rec->length_, rec->width_);
}