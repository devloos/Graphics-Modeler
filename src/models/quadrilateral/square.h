#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "models/shape.h"

class Square : public Shape {
 public:
  Square();
  virtual ~Square() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
