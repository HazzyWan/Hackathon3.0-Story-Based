#include "LinkedList.h"
#include <iostream>

Item::Item(const std::string& itemName, const std::string& itemDescription) :
    name(itemName), description(itemDescription) {}

std::string Item::getName() const {
    return name;
}

std::string Item::getDescription() const {
    return description;
}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insert(Item* newItem) {
    Node* newNode = new Node;
    newNode->data = newItem;
    newNode->next = head;
    head = newNode;
}

void LinkedList::remove(Item* itemToRemove) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == itemToRemove) {
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

Item* LinkedList::search(const std::string& itemName) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data->getName() == itemName) {
            return current->data;
        }
        current = current->next;
    }

    return nullptr;
}

void LinkedList::display() {
    Node* current = head;

    while (current != nullptr) {
        std::cout << "Item: " << current->data->getName() << std::endl;
        std::cout << "Description: " << current->data->getDescription() << std::endl;
        current = current->next;
    }
}

