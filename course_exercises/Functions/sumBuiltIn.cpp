#include <iostream>

using namespace std;

int sumArray(int myArray[], int myArraySize)
{
    int sum = 0;
    for(int i = 0; i < myArraySize; i++)
    {
        sum += myArray[i];
    }
    return sum;
}

int main()
{
    int myArray[8] = {3,6,5,7,8,10,12,13};
    
    cout << "Array sum = " << sumArray(myArray, 8) << endl;

    return 0;
}