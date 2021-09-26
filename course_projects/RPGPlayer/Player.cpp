#include "Player.h"
#include <string>

Player::Player(string name, race Race, int hitPoints, int magicPoints)
    : name(name),
      Race(Race),
      hitPoints(hitPoints),
      magicPoints(magicPoints)
{
}

Player::~Player()
{
}

string Player::getName() const
{
    return this->name;
}

race Player::getRace() const
{
    return this->Race;
}

string Player::whatRace() const
{
    switch (this->Race)
    {
    case HUMAN:
        return "Human";
    case ELF:
        return "Elf";
    case DWARF:
        return "Dwarf";
    case ORC:
        return "Orc";
    case TROLL:
        return "Troll";
    default:
        return "No race";
    }
}

int Player::getHitPoints() const
{
    return this->hitPoints;
}

int Player::getMagicPoints() const
{
    return this->magicPoints;
}
