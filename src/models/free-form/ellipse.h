#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <cmath>
#include <memory>
#include <vector>

#include "models/shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Ellipse : public Shape {
 public:
  Ellipse();
  Ellipse(const Ellipse &) = delete;
  Ellipse &operator=(const Ellipse &) = delete;
  virtual ~Ellipse() noexcept;

 public:
  // Getters and Setters

  void setMajorAxis(const int &majorAxis);
  int getMajorAxis() const;

  void setMinorAxis(const int &minorAxis);
  int getMinorAxis() const;

 public:
  /**
   * @brief returns pi * majorAxis * minorAxis
   *
   * @return float
   */
  float area() const override;

  /**
   * @brief IMPORTANT - returns an approximation
   * this approximation is within 5% of true value
   * as long as the major axis is not more than 3
   * times longer than the minor axis.
   *
   * returns 2 * pi * sqrt((a^2 + b^2) /2)
   * where b = majorAxis and a = minorAxis
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
  int majorAxis_ = 0;
  int minorAxis_ = 0;
};
