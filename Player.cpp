#include "Player.h"
using namespace std;

Player::Player(const string& playerName, const string& startingLocation) :
    name(playerName), currentLocation(startingLocation){}

string Player::getName() const {
    return name;
}

string Player::getCurrentLocation() const {
    return currentLocation;
}

LinkedList& Player::getInventory() {
    return inventory;
}

void Player::move(const string& newLocation) {
    currentLocation = newLocation;
}
