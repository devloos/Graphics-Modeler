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
  textAlignment_ = alignment;
}

void Text::setFontSize(int size) {
  fontSize_ = size;
}

void Text::setFontFamily(std::string family) {
  fontFamily_ = family;
}

void Text::setFontStyle(QFont::Style style) {
  fontStyle_ = style;
}

void Text::setFontWeight(QFont::Weight weight) {
  fontWeight_ = weight;
}

// Getters
QString Text::getText() const {
  return text_;
}

Qt::AlignmentFlag Text::getTextAlignment() const {
  return textAlignment_;
}

int Text::getFontSize() const {
  return fontSize_;
}

std::string Text::getFontFamily() const {
  return fontFamily_;
}

QFont::Style Text::getFontStyle() const {
  return fontStyle_;
}

QFont::Weight Text::getFontWeight() const {
  return fontWeight_;
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
  return -1;
}

float Text::perimeter() const {
  return -1;
}

void Text::paint(QPainter* painter) {
  Text* text = (Text*)(shapes.at(7).get());

  painter->setFont(QFont(
      text->fontFamily_.c_str(), text->fontSize_, text->fontWeight_, text->fontStyle_));
  painter->setPen(QColor(text->color_.c_str()));
  painter->drawText(
      QRect(text->points_[0].x(), text->points_[0].y(), text->length_, text->width_),
      text->text_);
}
