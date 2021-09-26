#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include <string>

using namespace std;

class Warrior : public Player
{
    public:
        Warrior(string name, race Race, int hitPoints, int magicPoints);
        string attack() const;

};

Warrior::Warrior(string name, race Race, int hitPoints, int magicPoints)
    : Player(name, Race, hitPoints, magicPoints)
{
}

string Warrior::attack() const
{
    return "I will destroy you with my sword and shield, foul demon!";
}

#endif