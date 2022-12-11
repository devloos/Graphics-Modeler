#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "models/shape.h"

class Polygon : public Shape {
 public:
  Polygon();
  virtual ~Polygon() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
