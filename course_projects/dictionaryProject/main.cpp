#include "Dictionary.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

enum option : unsigned char {ADD, GET, PRINT};

void checkValidInput(int selection);

int main()
{
    Dictionary userDictionary;
    int userSelection;
    string userWord;
    string userDefinition;

    while(true)
    {
        cout << "Type in your selection: \n"
             << "\t1 - Add a new word and definition\n"
             << "\t2 - Get the definition for a word\n"
             << "\t3 - Print all definitions\n" 
             << "\t0 - Exit" << endl;

        cin >> userSelection;

        if (userSelection == 0) { break; }

        cin.get();

        try
        {
            checkValidInput(userSelection);
            userSelection = static_cast<option>(userSelection-1);

            switch (userSelection)
            {
            case ADD:
                cout << "What is the word?\n";
                getline(cin, userWord);
                cout << "What is the definition?\n";
                getline(cin, userDefinition);
                userDictionary.addDefinition(userWord, userDefinition);
                break;

            case GET:
                cout << "Which word would you like the definition for?\n";
                getline(cin, userWord);
                cout << "Definition: " << userDictionary.getDefinition(userWord) << endl;
                break;

            case PRINT:
                userDictionary.printAll();
                break;
            }
        }
        catch(const invalid_argument& err)
        {
            cerr << err.what() << '\n';
            continue;
        }        
    }

    return 0;
}

void checkValidInput(int selection)
{
    if ( !(selection >= 1 && selection <= 3) )
    {
        throw invalid_argument("Please choose a valid option.");
    }
}
