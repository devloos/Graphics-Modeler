#include "text.h"

Text::Text() {}
Text::Text(const QString &str) : text(str) {}

Text::~Text() noexcept {}

float Text::area() const {
  return 0;
}

float Text::perimeter() const {
  return 0;
}

void Text::paint(QPainter* painter) {
  std::cout << "Text\n";
}

// More text-specific --------------------------------------

// Setters
void Text::setText(const QString &str) {
  text = str;
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
  return text;
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
