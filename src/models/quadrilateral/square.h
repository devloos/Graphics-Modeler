#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <vector>

#include "models/shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Square : public Shape {
 public:
  Square();
  Square(const Square &) = delete;
  Square &operator=(const Square &) = delete;
  virtual ~Square() noexcept;

 public:
  // Getters and Setters

  void setLength(const int &length);
  int getLength() const;

 public:
  /**
   * @brief returns length_^2
   *
   * @return float
   */
  float area() const override;

  /**
   * @brief returns 4 * length
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
  int length_ = 0;
};
