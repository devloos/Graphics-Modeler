#pragma once

#include "shape.h"

class Polyline : public Shape {
 public:
  Polyline();
  virtual ~Polyline() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
