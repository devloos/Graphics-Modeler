#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <vector>

#include "models/shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Polygon : public Shape {
 public:
  Polygon();
  virtual ~Polygon() noexcept;

  /**
   * @brief returns -1, becuase there is no
   * guarantee that it is a regular polygon, thus
   * no accurate way to calculate the area
   *
   * function not in use
   *
   * @return float
   */
  float area() const override;

  /**
   * @brief returns -1, becuase there is no
   * guarantee that it is a regular polygon, thus
   * no accurate way to calculate the perimeter
   *
   * function not in use
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
