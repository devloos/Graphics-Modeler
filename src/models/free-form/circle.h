#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <vector>

#include "models/shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Circle : public Shape {
 public:
  Circle();
  Circle(const Circle &) = delete;
  Circle &operator=(const Circle &) = delete;
  virtual ~Circle() noexcept;

 public:
  // Getters and Setter

  void setRadius(const int &radius);
  int getRadius() const;

 public:
  /**
   * @brief returns pi * r^2
   *
   * @return float
   */
  float area() const override;

  /**
   * @brief returns 2 * pi * r
   *
   * @return float
   */
  float perimeter() const override;

  /**
   * @brief Gets called on instatiation of the
   * object from qml. Uses QPainter to render the
   * properties of the shape.
   * IMPORTANT: Not using the propertes of the instantiated
   * object. Using the properties of the current shape
   * selected in the global (extern) vector.
   *
   * @param painter
   */
  void paint(QPainter* painter) override;

 private:
  int radius_ = 0;
};
