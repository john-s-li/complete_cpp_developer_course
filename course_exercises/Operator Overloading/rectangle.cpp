#include "rectangle.h"

rectangle::rectangle()
{
    this->width = 0;
    this->height = 0;
}

rectangle::rectangle(int w, int h)
{
    this->width = w;
    this->height = h;
}

int rectangle::getWidth() const
{
    return this->width;
}

int rectangle::getHeight() const
{
    return this->height;
}

int rectangle::getArea() const
{
    return this->width * this->height;
}

int rectangle::getPerimeter() const
{
    return 2*this->width + 2*this->height;
}

bool rectangle::operator==(const rectangle& other) const
{
    return (this->width == other.width && this->height == other.height);
}

bool rectangle::operator!=(const rectangle& other) const
{
    return (this->width != other.width || this->height != other.height);
}

rectangle rectangle::operator+(const rectangle& other) const
{
    rectangle newRect = rectangle(this->width + other.width, this->height + other.height);
    return newRect;
}

void rectangle::operator=(const rectangle& other)
{
    this->height = other.height;
    this->width = other.width;
}