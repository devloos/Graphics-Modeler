#include "text.h"

Text::Text() {}
Text::Text(const QString &str) : text_(str) {}

Text::~Text() noexcept {}

// More text-specific --------------------------------------

// Setters
void Text::setText(const QString &str) {
  text_ = str;
}

void Text::setTextAlignment(Qt::AlignmentFlag alignment) {
  textAlignment = alignment;
}

void Text::setFontSize(int size) {
  fontSize = size;
}

void Text::setFontFamily(std::string family) {
  fontFamily = family;
}

void Text::setFontStyle(QFont::Style style) {
  fontStyle = style;
}

void Text::setFontWeight(QFont::Weight weight) {
  fontWeight = weight;
}

// Getters
QString Text::getText() const {
  return text_;
}

Qt::AlignmentFlag Text::getTextAlignment() const {
  return textAlignment;
}

int Text::getFontSize() const {
  return fontSize;
}

std::string Text::getFontFamily() const {
  return fontFamily;
}

QFont::Style Text::getFontStyle() const {
  return fontStyle;
}

QFont::Weight Text::getFontWeight() const {
  return fontWeight;
}

void Text::setLength(const int &length) {
  length_ = length;
}

int Text::getLength() const {
  return length_;
}

void Text::setWidth(const int &width) {
  width_ = width;
}

int Text::getWidth() const {
  return width_;
}

void Text::setColor(const std::string &color) {
  color_ = color;
}

std::string Text::getColor() const {
  return color_;
}

float Text::area() const {
  return 0;
}

float Text::perimeter() const {
  return 0;
}

void Text::paint(QPainter* painter) {
  std::cout << "Text\n";
  Text* text = (Text*)(shapes.at(7).get());

  painter->setFont(
      QFont(text->fontFamily.c_str(), text->fontSize, text->fontWeight, text->fontStyle));
  painter->setPen(QColor(text->color_.c_str()));
  painter->drawText(
      QRect(text->points_[0].x(), text->points_[0].y(), text->length_, text->width_),
      text->text_);
}
