#include <iostream>
#include <array>

using namespace std;

int main()
{
    int userInput;
    const int ARRAY_SIZE = 5;
    array<int, ARRAY_SIZE> userData;

    for(int i = 0; i < userData.size(); i++)
    {
        cout << "Please enter an integer." << endl;
        cin >> userInput;
        userData[i] = userInput;
    }

    for(int i = 0; i < userData.size(); i++)
    {
        cout << "Twice of index " << i << " = " << 2 * userData[i] << endl;
    }
    
    return 0;
}
