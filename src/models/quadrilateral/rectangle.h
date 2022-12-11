#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <vector>

#include "models/shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Rectangle : public Shape {
 public:
  Rectangle();
  virtual ~Rectangle() noexcept;

 public:
  void setLength(const int &length);
  int getLength() const;

  void setWidth(const int &width);
  int getWidth() const;

 public:
  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;

 private:
  int length_ = 0;
  int width_ = 0;
};
