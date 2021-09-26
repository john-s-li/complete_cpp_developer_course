#include <iostream>
#include <string>

using namespace std;

int main()
{

    string fullName;
    string location;
    int initialScore;

    cout << "Please enter your intitial score (0 - 100):" << endl;
    cin >> initialScore;

    cin.get(); // need this because cin leaves a \n which will
               // be read in by getline() and that prompt will be skipped

    cout << "Please enter your full name:" << endl;
    getline(cin, fullName);

    cout << "Please enter your location (city, province, country):" << endl;
    getline(cin, location);

    

    cout << "Hello, " << fullName << "!" << endl;
    cout << "We heard that you are from " << location << "." << endl;
    cout << "Your initial score was " << initialScore << " and your score with an additional 5 points is " 
    << initialScore + 5 << "." << endl;

    return 0;
}