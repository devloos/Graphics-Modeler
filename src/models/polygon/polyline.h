#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <vector>

#include "models/shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Polyline : public Shape {
 public:
  Polyline();
  Polyline(const Polyline &) = delete;
  Polyline &operator=(const Polyline &) = delete;
  virtual ~Polyline() noexcept;

  /**
   * @brief returns -1 because it doesnt make sense
   * for a line to have an area. But area and perimeter are
   * pure virtual functions and it was a requirement of
   * the rubric that line inherits from Shape.
   *
   * @return float
   */
  float area() const override;

  /**
   * @brief returns -1 because it doesnt make sense
   * for a line to have a perimeter. But area and perimeter are
   * pure virtual functions and it was a requirement of
   * the rubric that line inherits from Shape.
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
};
