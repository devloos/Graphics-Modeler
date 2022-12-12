#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <memory>
#include <string>
#include <vector>

#include "shape.h"

extern std::vector<std::unique_ptr<Shape>> shapes;

class Text : public Shape {
 public:
  Text();
  Text(const QString &str);
  Text(const Text &) = delete;
  Text &operator=(const Text &) = delete;
  virtual ~Text() noexcept;

 public:
  // Setters and Getters

  void setText(const QString &str);
  QString getText() const;

  void setTextAlignment(Qt::AlignmentFlag alignment);
  Qt::AlignmentFlag getTextAlignment() const;

  void setFontSize(int size);
  int getFontSize() const;

  void setFontFamily(std::string family);
  std::string getFontFamily() const;

  void setFontStyle(QFont::Style style);
  QFont::Style getFontStyle() const;

  void setFontWeight(QFont::Weight weight);
  QFont::Weight getFontWeight() const;

  void setLength(const int &length);
  int getLength() const;

  void setWidth(const int &width);
  int getWidth() const;

  void setColor(const std::string &color);
  std::string getColor() const;

 public:
  /**
   * @brief returns -1 because it doesnt make sense
   * for text to have a perimeter. But area and perimeter are
   * pure virtual functions and it was a requirement of
   * the rubric that line inherits from Shape.
   *
   * @return float
   */
  float area() const override;

  /**
   * @brief returns -1 because it doesnt make sense
   * for text to have a perimeter. But area and perimeter are
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

 private:
  QString text_;
  Qt::AlignmentFlag textAlignment;
  std::string fontFamily;
  QFont::Style fontStyle;
  QFont::Weight fontWeight;
  std::string color_;
  int fontSize = 12;
  int length_ = 0;
  int width_ = 0;
};
