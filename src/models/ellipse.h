#pragma once

#include "shape.h"

class Ellipse : public Shape {
 public:
  Ellipse();
  virtual ~Ellipse() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
