#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "shape.h"

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
  int getwidth() const;

 public:
  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;

 private:
  QString text;
  Qt::AlignmentFlag textAlignment;
  std::string fontFamily;
  QFont::Style fontStyle;
  QFont::Weight fontWeight;
  int fontSize = 12;
  int length_ = 0;
  int width_ = 0;
};
