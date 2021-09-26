#include <iostream>
#include <array>


using namespace std;

int sumArrayObject(array<int, 10> myArray)
{
    int sum = 0;
    for(int i = 0; i < myArray.size(); i++)
    {
        sum += myArray[i]; 
    }
    return sum;
}

void sumArrayObject(array<int, 10> myArray, int& sum)
{
    for(int i = 0; i < myArray.size(); i++)
    {
        sum += myArray[i]; 
    }
}

int main()
{
    const int ARRAY_SIZE = 10;
    array<int,ARRAY_SIZE> userArray = {1,3,5,7,9,11,13,15,17,19};
    int sum = 0;

    cout << "The array sum is = " << sumArrayObject(userArray) << endl;
    sumArrayObject(userArray, sum);
    cout << "The array sum using passing by reference is = " << sum << endl;
    return 0;
}