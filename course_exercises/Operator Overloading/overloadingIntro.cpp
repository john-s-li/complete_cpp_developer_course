#include "rectangle.h"
#include <iostream>

using namespace std;

int main()
{
    rectangle rect1(10,20);
    rectangle rect2(50, 100);
    rectangle rect3(10,20);
    rectangle resultRect;

    resultRect = rect1 + rect2;

    cout << "rect1 == rect3? " << boolalpha << (rect1 == rect3) << endl;
    cout << "rect1 != rect2? " << (rect1 != rect2) << endl;

    cout << "resultRect: \n" 
         << "\tWidth = " << resultRect.getWidth() << endl
         << "\tHeight = " << resultRect.getHeight() << endl;

    return 0;
}