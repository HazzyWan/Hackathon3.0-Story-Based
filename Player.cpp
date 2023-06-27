#include "Player.h"
using namespace std;

// Player class constructor
Player::Player(const string& playerName, const string& startingLocation) :
    name(playerName), currentLocation(startingLocation) {}
    
// Get the name of the player
string Player::getName() const {
    return name;
}

// Get the current location of the player
string Player::getCurrentLocation() const {
    return currentLocation;
}

// Get the inventory of the player
LinkedList& Player::getInventory() {
    return inventory;
}

// Move the player to a new location
void Player::move(const string& newLocation) {
    currentLocation = newLocation;
}

