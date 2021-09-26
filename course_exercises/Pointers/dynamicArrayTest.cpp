#include <iostream>

using namespace std;

int main()
{
    int array_size;
    cout << "Please enter the length/size of the array: \n";
    cin >> array_size;

    // Allocating a dynamic array allows for an array to 
    // have dynamic length, rather than static as for the normal built-in array
    int* myArray = new int[array_size];

    for(int i = 0; i < array_size; i++)
    {
        myArray[i] = i * 2;
    }

    for(int i = 0; i < array_size; i++)
    {
        cout << "Value of myArray @ index " << i << " = " << myArray[i] << endl;
    }

    delete[] myArray;

    return 0;
}