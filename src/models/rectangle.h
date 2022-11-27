#pragma once

#include "shape.h"

class Rectangle : Shape {
 public:
  Rectangle();
  virtual ~Rectangle();

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
