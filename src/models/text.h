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
  virtual ~Text() noexcept;

 public:
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
  float area() const override;
  float perimeter() const override;
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
