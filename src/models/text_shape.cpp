#include "text_shape.h"

Text::Text(QString str)
    :textStr(str)
{
    
}

Text::~Text()
{

}

float Text::area() const
{
    return 0;
}

float Text::perimeter() const
{
    return 0;
}

void Text::draw() const
{
    // getPoints and call QPainter.drawLine(Qpoint......)
}

void Text::move()
{

}


// More text-specific --------------------------------------

// Setters
void Text::setText(QString str) { textStr = str; }
void Text::setTextAlignment(Qt::AlignmentFlag alignment) { textAlignment = alignment; }
void Text::setFontSize(int size) { fontSize = size; }
void Text::setFontFamily(std::string family) { fontFamily = family; }
void Text::setFontStyle(QFont::Style style) { fontStyle =  style; }
void Text::setFontWeight(QFont::Weight weight) { fontWeight = weight; }

// Getters
QString Text::getText() const { return textStr; }
Qt::AlignmentFlag Text::getTextAlignment() const { return textAlignment; }
int Text::getFontSize() const { return fontSize; }
std::string Text::getFontFamily() const { return fontFamily; }
QFont::Style Text::getFontStyle() const { return fontStyle; }
QFont::Weight Text::getFontWeight() const { return fontWeight; }

