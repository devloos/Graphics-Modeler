#pragma once

#include "models/shape.h"

class Rectangle : public Shape {
 public:
  Rectangle();
  virtual ~Rectangle() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
