#include <iostream>

using namespace std;

int main()
{
    int myInt = 150;
    int* myIntPtr = &myInt; // Set pointer to memory address of myInt

    double myDouble = 3.14;
    double* myDoublePtr = &myDouble;

    bool* myBoolPtr = new bool; // make dynamically allocated pointer in heap
    *myBoolPtr = true; // deref it and give it a value

    cout << boolalpha;

    cout << "myInt = " << myInt << endl;
    cout << "myInt address = " << myIntPtr << endl;

    cout << "myDouble = " << myDouble << endl;
    cout << "myDouble address = " << myDoublePtr << endl;

    cout << "myBoolPtr value = " << *myBoolPtr << endl;
    cout << "myBoolPtr address = " << myBoolPtr << endl;

    // Dereference the pointer and change the value of myInt
    *myIntPtr = 200;
    
    cout << "Now, the value of myInt = " << myInt << endl;
    cout << "Dereferenced myDoublePtr = " << *myDoublePtr << endl;

    delete myBoolPtr; // release memory back to heap
    myBoolPtr = nullptr; // remember to remove invalid pointer address

    cout << "Cleaning up memory from myBoolPtr" << endl;
    cout << "Value of myBoolPtr = " << myBoolPtr << endl;

    return 0;
}