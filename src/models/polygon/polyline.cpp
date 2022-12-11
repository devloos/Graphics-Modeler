#include "polyline.h"

Polyline::Polyline() {}

Polyline::~Polyline() noexcept {}

float Polyline::area() const {
  return 0;
}

float Polyline::perimeter() const {
  return 0;
}

void Polyline::paint(QPainter* painter) {
  std::cout << "Polyline\n";
  Polyline* polyline = (Polyline*)(shapes.at(1).get());

  painter->setPen(polyline->pen_);

  QList<QPoint> list;
  for (const auto &point : polyline->points_) {
    list.push_back(point);
  }

  painter->drawPolyline(QPolygon(list));
}