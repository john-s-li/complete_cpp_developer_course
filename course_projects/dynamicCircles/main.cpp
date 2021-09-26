#include <iostream>
#include "circle.h"

using namespace std;

int main()
{
    int numCircles;
    cout << "How many circles would you like?" << endl;
    cin >> numCircles;

    circle** circlePtrs = new circle*[numCircles]; // cannot put const in front

    int tempR;
    for(int i = 0; i < numCircles; i++)
    {
        cout << "\nWhat is the radius of Circle " << (i+1) << "?\n";
        cin >> tempR;
        circlePtrs[i] = new circle(tempR);

        cout << "The circumference of this circle is " << circlePtrs[i]->getCircumference() << endl;
        cout << "The area of this circle is " << circlePtrs[i]->getArea() << endl;
    }

    // Delete the circle ptrs
    for(int i = 0; i < numCircles; i++)
    {
        delete circlePtrs[i];
        circlePtrs[i] = nullptr;
    }

    return 0;
}