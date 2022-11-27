#pragma once

#include "models/shape.h"

class Square : public Shape {
 public:
  Square();
  virtual ~Square() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
