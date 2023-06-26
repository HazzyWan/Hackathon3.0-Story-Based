#include "LinkedList.h"
#include <iostream>
using namespace std;

// Item class constructor
Item::Item(const string& itemName, const string& itemDescription) :
    name(itemName), description(itemDescription) {}
// Get the name of the item
string Item::getName() const {
    return name;
}
// Get the description of the item
string Item::getDescription() const {
    return description;
}
// LinkedList class constructor
LinkedList::LinkedList() : head(nullptr) {}

// Insert a new item into the linked list
void LinkedList::insert(Item* newItem) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = newItem;
    newNode->next = head;
    head = newNode;
}
// Remove an item from the linked list
void LinkedList::remove(Item* itemToRemove) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == itemToRemove) {
            // Remove the node from the list
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}
// Search for an item in the linked list by its name
Item* LinkedList::search(const string& itemName) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data->getName() == itemName) {
            // Item found, return a pointer to it
            return current->data;
        }
        current = current->next;
    }
    // Item not found
    return nullptr;
}
// Display the items in the linked list
void LinkedList::display() {
    Node* current = head;

    while (current != nullptr) {
        // Print item name and description
        cout << "Item: " << current->data->getName() << endl;
        cout << "Description: " << current->data->getDescription() << endl;
        current = current->next;
    }
}

