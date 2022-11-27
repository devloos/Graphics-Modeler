#pragma once

#include "shape.h"

class Polyline : Shape
{

public:
    Polyline();
    virtual ~Polyline();

    float area() const override;
    float perimeter() const override;
    void draw() const override;
    void move() override;
};
