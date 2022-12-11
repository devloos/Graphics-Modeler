#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "shape.h"

class Line : public Shape {
 public:
  Line();
  virtual ~Line() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
