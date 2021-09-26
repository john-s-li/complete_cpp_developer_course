#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <string>
#include <ctime>

using namespace std;

bool is_digit_valid(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i])) { return false; }
    }

    return true;
} 

int main()
{
    srand(time(nullptr));

    string userGuess;
    int userGuess_int = 0;
    int computerGuess = (rand() % 100) + 1; // between 1 and 100


    
    cout << "Welcome to guess the number!" << endl;
    
    int count = 0;

    while (userGuess_int != computerGuess)
    {
        cout << "Please input an integer from 1 - 100." << endl;
        getline(cin, userGuess);

        if (!(is_digit_valid(userGuess)))
        {
            cout << "Not a proper integer input. Please try again.";
            continue;
        }

        userGuess_int = stoi(userGuess);
        count++;

        if (userGuess_int == computerGuess)
        {
            if (count == 1)
            {
                cout << "Wow! You guess correctly in " << count << " guess." << endl;
            }
            else
            {
                cout << "Wow! You guess correctly in " << count << " guesses." << endl;
            }

            break;
            
        }
        else if (userGuess_int > 100 || userGuess_int < 1)
        {
            cout << "That was a wasted guess. Please guess within 1 - 100!" << endl;
        }
        else if (userGuess_int < computerGuess)
        {
            cout << "You're too low. Guess higher!" << endl;
        }
        else if (userGuess_int > computerGuess)
        {
            cout << "You're too high. Guess lower!" << endl;
        }
    }

    return 0;
   
}