#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
#include <string>

using namespace std;

class Mage : public Player
{
    public:
        Mage(string name, race Race, int hitPoints, int magicPoints);
        string attack() const;

};

Mage::Mage(string name, race Race, int hitPoints, int magicPoints)
    : Player(name, Race, hitPoints, magicPoints)
{
}

string Mage::attack() const
{
    return "I will crush you with the power of my arcane missiles!";
}

#endif