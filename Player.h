#ifndef PLAYER_H
#define PLAYER_H

#include "LinkedList.h"
#include <string>

using namespace std; 
 
class Player {
private:
    string name;
    string currentLocation;
    LinkedList inventory;

public:
    Player(const std::string& playerName, const std::string& startingLocation);
    string getName() const;
    string getCurrentLocation() const;
    LinkedList& getInventory();
    void move(const string& newLocation);
};

#endif  // PLAYER_H
