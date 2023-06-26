#include "Room.h"

Room::Room(const std::string& roomDescription) : description(roomDescription) {
    // Initialize exits to empty strings
    for (int i = 0; i < 4; i++) {
        exits[i] = "";
    }
}

std::string Room::getDescription() const {
    return description;
}

void Room::addExit(const std::string& direction, const std::string& room) {
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

bool Room::hasExit(const std::string& direction) const {
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

std::string Room::getExit(const std::string& direction) const {
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
    return inventory;
}

void Room::setInventory(const LinkedList& newInventory) {
    inventory = newInventory;
}
