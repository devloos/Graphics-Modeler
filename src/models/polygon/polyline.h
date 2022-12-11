#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "models/shape.h"

class Polyline : public Shape {
 public:
  Polyline();
  virtual ~Polyline() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
