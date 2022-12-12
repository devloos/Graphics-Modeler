#include "polyline.h"

Polyline::Polyline() {}

Polyline::~Polyline() noexcept {}

float Polyline::area() const {
  return -1;
}

float Polyline::perimeter() const {
  return -1;
}

void Polyline::paint(QPainter* painter) {
  Polyline* polyline = (Polyline*)(shapes.at(1).get());

  painter->setPen(polyline->pen_);

  QList<QPoint> list;
  for (const auto &point : polyline->points_) {
    list.push_back(point);
  }

  painter->drawPolyline(QPolygon(list));
}