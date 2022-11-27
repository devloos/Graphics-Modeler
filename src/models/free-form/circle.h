#pragma once

#include "models/shape.h"

class Circle : public Shape {
 public:
  Circle();
  virtual ~Circle() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
