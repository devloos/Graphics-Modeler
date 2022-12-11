#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "models/shape.h"

class Rectangle : public Shape {
 public:
  Rectangle();
  virtual ~Rectangle() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
