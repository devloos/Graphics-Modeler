#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <vector>

#include "models/shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Polygon : public Shape {
 public:
  Polygon();
  virtual ~Polygon() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
