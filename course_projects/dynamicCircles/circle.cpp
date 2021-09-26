#include "circle.h"
#include <math.h>

using namespace std;

circle::circle(int r) : PI(3.14159)
{
    this->radius = r;
}

double circle::getArea() const
{
    return this->PI * pow(this->radius, 2);
}

double circle::getCircumference() const
{
    return 2 * this->PI * this->radius;
}