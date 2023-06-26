#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

class Item {
private:
    std::string name;
    std::string description;

public:
    Item(const std::string& itemName, const std::string& itemDescription);
    std::string getName() const;
    std::string getDescription() const;
};

struct Node {
    Item* data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insert(Item* newItem);
    void remove(Item* itemToRemove);
    Item* search(const std::string& itemName);
    void display();
};

#endif  // LINKEDLIST_H
