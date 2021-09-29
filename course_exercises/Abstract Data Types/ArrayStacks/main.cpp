#include "ArrayStack.hpp"
#include <iostream>

using namespace std;

int main()
{   
    int arrLength = 20;
    ArrayStack myArrayStack(arrLength);

    cout << "Pushing data onto Array Stack.\n";

    for(int i = 0; i < arrLength; i++)
    {
        myArrayStack.push(i);
    }

    cout << "Take a peek at Array Stack\n";
    cout << myArrayStack.peek() << endl;

    cout << "Popping from Array Stack 3 times\n";
    myArrayStack.pop();
    myArrayStack.pop();
    myArrayStack.pop();

    cout << "Now peeking again...\n";
    cout << myArrayStack.peek() << endl;

    return 0;
}