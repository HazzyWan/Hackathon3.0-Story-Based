#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"
using namespace std;

class Game {
private:
    Player player;           // Player object
    Room startRoom;          // Start room object
    Room treasureRoom;       // Treasure room object
    Room lockedRoom;         // Locked room object
    Room secretRoom;         // Secret room object
    Room exitHatch;          // Exit hatch room object

public:
    Game(const string& playerName);  // Constructor
    void run();  // Main game loop
};

#endif  // GAME_H

