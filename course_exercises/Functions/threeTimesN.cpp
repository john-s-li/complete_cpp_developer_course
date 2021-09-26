#include <iostream>

using namespace std;

void threeTimesN(int a, int& b)
{
    b = 3*a;
}

int main()
{
    int a = 5;
    int b = 2;

    cout << "Value of a = " << a << endl;
    cout << "Old value of b = " << b << endl;
    threeTimesN(a,b);
    cout << "New value of b = " << b << endl;
    return 0;
}