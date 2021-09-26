#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

// C++ 11 does not allow for forward definitions for enum
// must declare the size/type of data it stores
enum race : unsigned char { HUMAN, ELF, DWARF, ORC, TROLL};

class Player
{
    public:
        Player(string name, race Race, int hitPoints, int magicPoints);
        virtual ~Player() = 0; // need this to prevent compiler warning
        string getName() const;
        race getRace() const;
        string whatRace() const;
        int getHitPoints() const;
        int getMagicPoints() const;
        virtual string attack() const = 0;
        
    private:
        string name;
        race Race;
        int hitPoints;
        int magicPoints;

}; // end class

#endif