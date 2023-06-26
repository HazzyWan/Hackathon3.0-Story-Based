#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;

class Item {
private:
    string name;  // The name of the item
    string description;  // The description of the item

public:
    // Constructor
    Item(const string& itemName, const string& itemDescription);

    // Getter methods
    string getName() const;  // Returns the name of the item
    string getDescription() const;  // Returns the description of the item
};

struct Node {
    Item* data;  // Pointer to the item stored in the node
    Node* next;  // Pointer to the next node in the linked list
};

class LinkedList {
private:
    Node* head;  // Pointer to the head of the linked list

public:
    // Constructor
    LinkedList();
    // Insert a new item into the linked list
    void insert(Item* newItem);
    // Remove an item from the linked list
    void remove(Item* itemToRemove);
    // Search for an item by its name and return a pointer to it
    Item* search(const string& itemName);
    // Display the items in the linked list
    void display();
};

#endif  // LINKEDLIST_H

