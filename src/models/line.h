#pragma once

#include "shape.h"

class Line : Shape {
 public:
  Line();
  virtual ~Line();

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
