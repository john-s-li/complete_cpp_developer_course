#include <iostream>
#include <string>
#include "Swapper.hpp"

using namespace std;

template<class T> 
T getSmaller(T a, T b);

int main()
{
    Swapper<int> swap1 = Swapper<int>(2,5);
    Swapper<string> swap2 = Swapper<string>("John", "Christoph");

    cout << "Before swapping: \n"
         << "\tSwapper 1: \n"
         << "\t\tElement 1 = " << swap1.getFirst()
         << "\tElement 2 = " << swap1.getSecond() << endl;

    cout << "Before swapping: \n"
         << "\tSwapper 2: \n"
         << "\t\tElement 1 = " << swap2.getFirst()
         << "\tElement 2 = " << swap2.getSecond() << endl;

    swap1.swap();
    swap2.swap();

    cout << "After swapping: \n"
         << "\tSwapper 1: \n"
         << "\t\tElement 1 = " << swap1.getFirst()
         << "\tElement 2 = " << swap1.getSecond() << endl;

    cout << "After swapping: \n"
         << "\tSwapper 2: \n"
         << "\t\tElement 1 = " << swap2.getFirst()
         << "\tElement 2 = " << swap2.getSecond() << endl;

    cout << "Smaller of the 2 = " << getSmaller(swap1.getFirst(), swap1.getSecond()) << endl;

    return 0;
}

template<class T> 
T getSmaller(T a, T b)
{
    if (a > b) { return b; }
    return a;
}