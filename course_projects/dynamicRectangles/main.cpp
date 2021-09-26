#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
    const int ARRAY_SIZE = 3;
    const rectangle* rectPtrs[ARRAY_SIZE];

    // Create the dynamically allocated rectangles
    rectPtrs[0] = new rectangle(3,5);
    rectPtrs[1] = new rectangle(4,6);
    rectPtrs[2] = new rectangle(9,12);

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Area of Rectangle " << (i+1) << " = " << rectPtrs[i]->getArea() << endl;
        cout << "Perimeter of Rectangle " << (i+1) << " = " << rectPtrs[i]->getPerimeter() << endl;

        cout << endl;
    }

    // delete the pointers
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        delete rectPtrs[i];
        rectPtrs[i] = nullptr;
    }

    return 0;
}