#pragma once

#include "shape.h"

class Polygon : Shape {
 public:
  Polygon();
  virtual ~Polygon();

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
