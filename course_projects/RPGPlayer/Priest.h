#ifndef PRIEST_H
#define PRIEST_H

#include "Player.h"
#include <string>

using namespace std;

class Priest : public Player
{
    public:
        Priest(string name, race Race, int hitPoints, int magicPoints);
        string attack() const;
        
}; // end class

Priest::Priest(string name, race Race, int hitPoints, int magicPoints)
    : Player(name, Race, hitPoints, magicPoints)
{
}

string Priest::attack() const
{
    return "I will assault you with Holy Wrath!";
}

#endif