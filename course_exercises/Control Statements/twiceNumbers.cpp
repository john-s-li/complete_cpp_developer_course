#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 10> myArray;

    for(int i = 0; i < myArray.size(); i++)
    {
        myArray[i] = 2*i;
    }

    for(auto value : myArray)
    {
        cout << value << endl;
    }

    return 0;
}