#include "line.h"

Line::Line() {}

Line::~Line() noexcept {}

float Line::area() const {
  return -1;
}

float Line::perimeter() const {
  return -1;
}

void Line::paint(QPainter* painter) {
  Line* line = (Line*)(shapes.at(0).get());

  painter->setPen(line->pen_);
  painter->setBrush(line->pen_.brush());
  painter->drawLine(
      line->points_[0].x(), line->points_[0].y(), line->points_[1].x(),
      line->points_[1].y());
}