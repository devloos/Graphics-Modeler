#pragma once

#include "shape.h"

class Ellipse : Shape
{

public:
    Ellipse();
    virtual ~Ellipse();

    float area() const override;
    float perimeter() const override;
    void draw() const override;
    void move() override;
};
