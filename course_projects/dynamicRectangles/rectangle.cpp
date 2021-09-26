#include "rectangle.h"

rectangle::rectangle(int w, int h)
{
    this->width = w;
    this->height = h;
}

int rectangle::getArea() const
{
    return this->width * this->height;
}

int rectangle::getPerimeter() const
{
    return 2*this->width + 2*this->height;
}