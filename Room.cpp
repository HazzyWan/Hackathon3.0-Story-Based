#include "Room.h"
using namespace std;

Room::Room(const std::string& roomDescription) : description(roomDescription) {
    // Initialize exits to empty strings
    for (int i = 0; i < 4; i++) {
        exits[i] = "";
    }
}

string Room::getDescription() const {
    return description;
}

void Room::addExit(const string& direction, const string& room) {
    // Add an exit to the room in the specified direction
    // The direction can be "north", "south", "east", or "west"
    if (direction == "north") {
        exits[0] = room;
    } else if (direction == "south") {
        exits[1] = room;
    } else if (direction == "east") {
        exits[2] = room;
    } else if (direction == "west") {
        exits[3] = room;
    }
}

bool Room::hasExit(const string& direction) const {
    // Check if the room has an exit in the specified direction
    // Return true if an exit exists, false otherwise
    if (direction == "north") {
        return exits[0] != "";
    } else if (direction == "south") {
        return exits[1] != "";
    } else if (direction == "east") {
        return exits[2] != "";
    } else if (direction == "west") {
        return exits[3] != "";
    }
    return false;
}

string Room::getExit(const string& direction) const {
    // Get the room name of the exit in the specified direction
    // Return the room name if the exit exists, an empty string otherwise
    if (direction == "north") {
        return exits[0];
    } else if (direction == "south") {
        return exits[1];
    } else if (direction == "east") {
        return exits[2];
    } else if (direction == "west") {
        return exits[3];
    }
    return "";
}

LinkedList& Room::getInventory() {
    // Get the inventory of the room
    return inventory;
}

void Room::setInventory(const LinkedList& newInventory) {
    // Set the inventory of the room to the specified inventory
    inventory = newInventory;
}

