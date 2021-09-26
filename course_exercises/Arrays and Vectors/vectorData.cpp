#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userInput;
    vector<int> userData;

    cout << "Please enter a positive integer." << endl;
    cin >> userInput;

    while(userInput > 0)
    {
        userData.push_back(userInput);
        cout << "Please enter another positive integer. To stop, input a negative integer." << endl;
        cin >> userInput;
    }

    cout << "Here are the vector elements times 2." << endl;
    for(int num : userData)
    {
        cout << 2*num << endl;
    }
    
    return 0;
}