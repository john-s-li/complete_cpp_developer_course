#include "Player.h"
#include "Warrior.h"
#include "Priest.h"
#include "Mage.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> 

using namespace std;

// Function prototypes
void checkPlayerInput(int playerSelection);
race getRaceInput(int raceSelection);
void printPlayerInfos(vector<Player*>& playerPtrs);
void clearPlayerPtrs(vector<Player*>& playerPtrs);

int main()
{
    vector<Player*> playerPtrs;
    Player* newPlayer;

    int userPlayerSelection;
    int userRaceSelection;
    string userPlayerName;
    race userRace;

    while(true)
    {
        cout << "Which of the following would you like?" << endl
             << "\t1 - Create a Warrior" << endl
             << "\t2 - Create a Priest" << endl
             << "\t3 - Create a Mage" << endl
             << "\t0 - finish creating player characters" << endl;

        cin >> userPlayerSelection;

        if (userPlayerSelection == 0) { break; }

        try
        {
            checkPlayerInput(userPlayerSelection);
        }
        catch(const invalid_argument& err)
        {
            cerr << err.what() << '\n';
            continue;
        }

        cin.get(); // catch the \n left by cin

        cout << "What is the name of your player?\n";
        getline(cin, userPlayerName);

        cout << "\nWhich of the races would you like?" << endl
             << "\t1 - HUMAN" << endl
             << "\t2 - ELF" << endl
             << "\t3 - DWARF" << endl
             << "\t4 - ORC" << endl
             << "\t5 - TROLL" << endl;
        
        cin >> userRaceSelection;

        try
        {
            userRace = getRaceInput(userRaceSelection);
        }
        catch(const invalid_argument& err)
        {
            cerr << err.what() << '\n';
            continue;
        }       

        switch (userPlayerSelection)
        {
            case 1:
                newPlayer = new Warrior(userPlayerName, userRace, 200, 0);
                break;
            case 2:
                newPlayer = new Priest(userPlayerName, userRace, 100, 200);
                break;
            case 3:
                newPlayer = new Mage(userPlayerName, userRace, 150, 150);
                break;
        }

        playerPtrs.push_back(newPlayer);
    }

    printPlayerInfos(playerPtrs);
    clearPlayerPtrs(playerPtrs);

    cout << "Program complete.\n";

    return 0;
}

void checkPlayerInput(int playerSelection)
{
    if (playerSelection != 1 && playerSelection != 2 && playerSelection != 3)
        {
            throw invalid_argument("Please enter a valid value.\n");
        }
}

race getRaceInput(int raceSelection)
{
    if ( !(raceSelection >= 1 && raceSelection <= 5 ) )
    {
        throw invalid_argument("Invalid race. Please start over.\n");
    }

    return static_cast<race>(raceSelection - 1);
}

void printPlayerInfos(vector<Player*>& playerPtrs)
{
    for(Player* player : playerPtrs)
    {
        cout << "My name is " << player->getName() << " and I'm a "
             << player->whatRace() << ". My attack is : "
             << player->attack() << endl;
    }
}

void clearPlayerPtrs(vector<Player*>& playerPtrs)
{
    for(int i = 0; i < playerPtrs.size(); i++)
    {
        delete playerPtrs[i];
        playerPtrs[i] = nullptr; // don't forget to set nullptr or seg fault can happen
    }

    playerPtrs.clear();
}
