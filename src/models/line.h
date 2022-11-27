#pragma once

#include "shape.h"

class Line : public Shape {
 public:
  Line();
  virtual ~Line() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;
};
