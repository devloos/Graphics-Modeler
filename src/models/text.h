#pragma once

#include "shape.h"

class Text : Shape {
 public:
  Text();
  Text(const QString &str);
  virtual ~Text() noexcept;

  float area() const override;
  float perimeter() const override;
  void draw() const override;
  void move() override;

 public:
  void setText(const QString &str);
  void setTextAlignment(Qt::AlignmentFlag alignment);
  void setFontSize(int size);
  void setFontFamily(std::string family);
  void setFontStyle(QFont::Style style);
  void setFontWeight(QFont::Weight weight);

 public:
  QString getText() const;
  Qt::AlignmentFlag getTextAlignment() const;
  int getFontSize() const;
  std::string getFontFamily() const;
  QFont::Style getFontStyle() const;
  QFont::Weight getFontWeight() const;

 private:
  QString text;
  Qt::AlignmentFlag textAlignment;
  int fontSize = 12;
  std::string fontFamily;
  QFont::Style fontStyle;
  QFont::Weight fontWeight;
};
