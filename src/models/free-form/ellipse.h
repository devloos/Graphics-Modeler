#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "models/shape.h"

class Ellipse : public Shape {
 public:
  Ellipse();
  virtual ~Ellipse() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
