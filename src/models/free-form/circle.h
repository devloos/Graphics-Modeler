#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "models/shape.h"

class Circle : public Shape {
 public:
  Circle();
  virtual ~Circle() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
