#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"

class Game {
private:
    Player player;
    Room startRoom;
    Room treasureRoom;
    Room lockedRoom;
    Room secretRoom;
    Room exitHatch;

public:
    Game(const std::string& playerName);  // Constructor
    void run();
};

#endif  // GAME_H
