#ifndef GAME_H
#define GAME_H

#include <fstream>
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
    Room archiveRoom;        // Archive room object
    Room hallway;            // Hallway room object
    Room morgue;             // Morgue room object
    string fileName;

public:
    Game(const string& playerName);  // Constructor
    
    
    void run();  // Main game loop
    void readHistory(const string&);
    void writeHistory(string, string);
    void resetHistory();
    void readHistory();
    void setPlayerName(const string&);
    
};

#endif  // GAME_H

