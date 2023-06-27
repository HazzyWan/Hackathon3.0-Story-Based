#ifndef PLAYER_H
#define PLAYER_H

#include "LinkedList.h"
#include <string>

using namespace std;

class Player {
private:
    string name;                   // The name of the player
    string currentLocation;        // The current location of the player
    LinkedList inventory;          // The player's inventory stored as a linked list

public:
    Player(const std::string& playerName, const std::string& startingLocation); // Constructor that initializes the player's name and starting location

    string getName() const; // Getter method to retrieve the name of the player

    string getCurrentLocation() const; // Getter method to retrieve the current location of the player

    LinkedList& getInventory(); // Getter method to retrieve a reference to the player's inventory

    void move(const string& newLocation); // Method to update the player's current location to the specified new location
    
    void setName(const string& ) ;// Sets the player Name
};

#endif  // PLAYER_H

