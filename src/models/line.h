#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <vector>

#include "shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Line : public Shape {
 public:
  Line();
  virtual ~Line() noexcept;

  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;
};
