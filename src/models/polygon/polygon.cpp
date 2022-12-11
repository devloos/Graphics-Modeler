#include "polygon.h"

Polygon::Polygon() {}

Polygon::~Polygon() noexcept {}

float Polygon::area() const {
  return 0;
}

float Polygon::perimeter() const {
  return 0;
}

void Polygon::paint(QPainter* painter) {
  Polygon* polygon = (Polygon*)(shapes.at(2).get());

  painter->setPen(polygon->pen_);
  painter->setBrush(polygon->pen_.brush());

  QList<QPoint> list;
  for (const auto &point : polygon->points_) {
    list.push_back(point);
  }

  painter->drawPolygon(QPolygon(list));
}
