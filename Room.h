#ifndef ROOM_H
#define ROOM_H

#include "LinkedList.h"
#include <string>

class Room {
private:
    std::string description;
    std::string exits[4];  // Exits from the room: [north, south, east, west]
    LinkedList inventory;

public:
    Room(const std::string& roomDescription);
    std::string getDescription() const;
    void addExit(const std::string& direction, const std::string& room);
    bool hasExit(const std::string& direction) const;
    std::string getExit(const std::string& direction) const;
    LinkedList& getInventory();
    void setInventory(const LinkedList& newInventory);
};

#endif  // ROOM_H
