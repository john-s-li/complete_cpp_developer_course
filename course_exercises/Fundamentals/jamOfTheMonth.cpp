#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    int numJammies;
    int sum;
    int additionalCharge;
    char packageType;

    cout << "What type of package do you have? A, B, or C?" << endl;
    cin >> packageType;

    if (tolower(packageType) != 'a' && tolower(packageType) != 'b' &&
        tolower(packageType) != 'c')
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    cout << "How many jams did you buy?" << endl;
    cin >> numJammies;

    if (tolower(packageType) == 'a')
    {
        if (numJammies <= 2) 
        {
            additionalCharge = 0;
        }
        else
        { 
            additionalCharge = 5 * (numJammies - 2);
        }
        sum = 8 + additionalCharge;
    }
    else if (tolower(packageType) == 'b')
    {
        if (numJammies <= 4) 
        {
            additionalCharge = 0;
        }
        else
        { 
            additionalCharge = 4 * (numJammies - 4);
        }
        sum = 12 + additionalCharge;
    }
    else
    {
        if (numJammies <= 6) 
        {
            additionalCharge = 0;
        }
        else
        { 
            additionalCharge = 3 * (numJammies - 6);
        }
        sum = 15 + additionalCharge;
    }

    cout << "You owe $" << sum << "." << endl;

    return 0;
}
