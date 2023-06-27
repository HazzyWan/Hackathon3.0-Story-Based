#ifndef ROOM_H
#define ROOM_H

#include "LinkedList.h"  // Include the LinkedList header file
#include <string>
using namespace std;

class Room {
private:
    string description;  // The description of the room
    string exits[4];  // Exits from the room: [north, south, east, west]
    LinkedList inventory;  // The inventory of the room

public:
    // Constructor
    Room(const string& roomDescription);
    
    // Getter method for the description
    string getDescription() const;
    
    // Add an exit to the room
    void addExit(const string& direction, const string& room);
    
    // Check if the room has an exit in the given direction
    bool hasExit(const string& direction) const;
    
    // Get the room name of the exit in the given direction
    string getExit(const string& direction) const;
    
    // Getter method for the inventory
    LinkedList& getInventory();
    
    // Setter method for the inventory
    void setInventory(const LinkedList& newInventory);
};

#endif  // ROOM_H

