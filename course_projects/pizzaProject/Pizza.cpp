#include "Pizza.h"
#include <iostream>

using namespace std;

Pizza::Pizza(string name, int diameter, int cost)
{
    this->name = name;
    this->diameter = diameter;
    this->cost = cost;
    this->toppings.push_back("Cheese");
}

void Pizza::addTopping(string topping)
{
    this->toppings.push_back(topping);
}

int Pizza::getCost() const
{
    return this->cost;
}

void Pizza::printToppings() const
{
    cout << "Here are the toppings for the " << this->diameter << " inch "
         << this->name << " Pizza:" << endl;
    for (string topping : this->toppings)
    {
        cout << topping << " ";
    }
    cout << endl;
}