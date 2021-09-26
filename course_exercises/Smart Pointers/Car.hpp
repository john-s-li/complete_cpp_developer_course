#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car
{
    public:
        Car(string color, int numDoors);
        string getColor() const;
        int getNumDoors() const;
    private:
        string color;
        int numDoors;
};

Car::Car(string color, int numDoors) 
    : color(color), numDoors(numDoors)
{
}

string Car::getColor() const
{
    return this->color;
}

int Car::getNumDoors() const
{
    return this->numDoors;
}

#endif

