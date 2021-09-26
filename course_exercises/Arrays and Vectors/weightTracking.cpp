#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> userNames;
    vector<int> userWeights;

    string userName;
    int userWeight;

    const int NUM_INPUTS = 5;

    for(int i = 0; i < NUM_INPUTS; i++)
    {
        cout << "Please enter a name:" << endl;
        getline(cin, userName);

        cout << "Please enter " << userName << "'s weight." << endl;
        cin >> userWeight;

        cin.get(); // grab the \n

        userNames.push_back(userName);
        userWeights.push_back(userWeight);
    }

    for(int i = 0; i < NUM_INPUTS; i++)
    {
        cout << userNames[i] << "'s weight is " << userWeights[i] << " lbs." << endl;
    }

    return 0;
}