#pragma once

#include "shape.h"

class Text : Shape
{

public:
    Text();
    virtual ~Text();

    float area() const override;
    float perimeter() const override;
    void draw() const override;
    void move() override;
};
