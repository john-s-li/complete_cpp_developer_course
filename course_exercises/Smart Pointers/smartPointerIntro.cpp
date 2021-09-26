#include <iostream>
#include <memory>
#include "Car.hpp"

using namespace std;

int main()
{
    // Single variables ---
    // has its own memory location...CANNOT be shared
    {
        unique_ptr<double> myDubPtr = make_unique<double>(); 
        *myDubPtr = 3.14;
        cout << "Location of myDubPtr = " << myDubPtr << endl;
        cout << "Value of myDubPtr = " << *myDubPtr << endl;

        // Must move ownership
        unique_ptr<double> otherPtr = move(myDubPtr);

        cout << "Other pointer is " << *otherPtr << endl;
    }

    // Arrays ---
    {
        const int ARRAY_SIZE = 5;
        auto myArray = make_unique<int[]>(ARRAY_SIZE);

        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            myArray[i] = i * 2;
        }

        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            cout << "Array element " << i << " = " << myArray[i] << endl;
        }
    }

    // Classes
    {
        unique_ptr<Car> CarPtr = make_unique<Car>("red",4);

        cout << "Car color = " << CarPtr->getColor() << endl;
        cout << "Num car doors = " << CarPtr->getNumDoors() << endl;
    }

    return 0;
}