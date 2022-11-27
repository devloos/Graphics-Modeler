#pragma once

#include "models/shape.h"

class Polygon : public Shape {
 public:
  Polygon();
  virtual ~Polygon() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
