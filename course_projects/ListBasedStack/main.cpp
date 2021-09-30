#include "ListStack.hpp"
#include <iostream>

using namespace std;

int main()
{   
    int arrLength = 20;
    ListStack myListStack;

    cout << "Pushing data onto List Stack.\n";

    for(int i = 0; i < arrLength; i++)
    {
        myListStack.push(i);
    }

    cout << "Take a peek at List Stack\n";
    cout << myListStack.peek() << endl;

    cout << "Popping from List Stack 3 times\n";
    myListStack.pop();
    myListStack.pop();
    myListStack.pop();

    cout << "Now peeking again...\n";
    cout << myListStack.peek() << endl;

    return 0;
}