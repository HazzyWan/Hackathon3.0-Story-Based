#include "Game.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Game::Game(const string& playerName) :
    player(playerName, "StartRoom"),
    startRoom("The room is consumed by darkness, with only faint traces of light seeping through tiny cracks in the\nancient stone walls. The air hangs heavy with a damp, musty scent, and a chilling coldness\nemanates from the rough, unyielding floor, intensifying the sense of isolation and confinement."),
    treasureRoom("You found a room full of treasures."),
    lockedRoom("You entered a locked room."),
    secretRoom("You discovered a hidden secret room."),
    exitHatch("")
{
    // Add exits to the rooms
    startRoom.addExit("north", "TreasureRoom");
    treasureRoom.addExit("south", "StartRoom");
    treasureRoom.addExit("east", "LockedRoom");
    lockedRoom.addExit("west", "TreasureRoom");
    lockedRoom.addExit("north", "SecretRoom");
    secretRoom.addExit("south", "LockedRoom");
    secretRoom.addExit("east", "ExitHatch");
    exitHatch.addExit("west", "SecretRoom");

    // Insert items into player's inventory
    player.getInventory().insert(new Item("Sword", "A shiny sword"));

    // Insert items into room's inventory
    treasureRoom.getInventory().insert(new Item("Key", "A golden key"));
}

void Game::run() {
    // Game loop
    string password;
    while (true) {
        // Print player's name, current location, and inventory
        cout << "====================================================================================================================== " << endl;
        cout << "Player Name: " << player.getName() << endl;
        cout << "Current Location: " << player.getCurrentLocation() << endl;
        cout << "====================================================================================================================== " << endl;
        cout << "Inventory:" << endl;
        player.getInventory().display();
        cout << "====================================================================================================================== " << endl;

        // Display room description
        string currentLocation = player.getCurrentLocation();
        if (currentLocation == "StartRoom") {
            cout << startRoom.getDescription() << endl;
        } else if (currentLocation == "TreasureRoom") {
            cout << treasureRoom.getDescription() << endl;
            cout << "You see a key in the room. Do you want to retrieve it? (yes/no): ";
            string retrieveKey;
            cin >> retrieveKey;

            if (retrieveKey == "yes") {
                // Retrieve the key from the treasure room's inventory
                Item* retrievedKey = treasureRoom.getInventory().search("Key");

                if (retrievedKey != nullptr) {
                    // Add the key to the player's inventory
                    player.getInventory().insert(retrievedKey);
                    cout << "You retrieved the key and added it to your inventory." << endl;

                    // Remove the key from the treasure room's inventory
                    treasureRoom.getInventory().remove(retrievedKey);
                } else {
                    cout << "You cannot find the key in the room." << endl;
                }
            }
        } else if (currentLocation == "LockedRoom") {
            cout << lockedRoom.getDescription() << endl;
        } else if (currentLocation == "SecretRoom") {
            cout << secretRoom.getDescription() << endl;
        } else if (currentLocation == "ExitHatch") {
            cout << exitHatch.getDescription() << endl;
            cout << "To open the Exit Hatch, enter the password: ";// Must enter the correct password so the player can proceed to escape

            cin >> password;

            if (password == "MELODY") {
                cout << "Congratulations! You have entered the correct password. You successfully escaped!" << endl;
                break;
            }else{
	            cout << "Wrong password. The Exit Hatch remains locked." << endl;//Wrong password will cause the player to choose which direction to explore again.
                system("pause");
                system("cls"); 
            }
            
        }
        
        // Prompt for user input
        cout << "---------------------------------------------------------------------------------------------------------------------- " << endl;
        cout << "Enter a direction to move (north, south, east, west) or 'quit' to exit the game: ";
        string input;
        cin >> input;
        system("cls");

        // Process user input
        if (input == "quit") {
            break;  // Exit the game
        } else if (input == "north" || input == "south" || input == "east" || input == "west" || input == "exit") {
            string newRoom;
            if (currentLocation == "StartRoom") {
                if (startRoom.hasExit(input)) {
                    newRoom = startRoom.getExit(input);
                } else {
                    cout << "There is no exit in that direction." << endl;
                    continue;
                }
            } else if (currentLocation == "TreasureRoom") {
                if (treasureRoom.hasExit(input)) {
                    newRoom = treasureRoom.getExit(input);
                } else {
                    cout << "There is no exit in that direction." << endl;
                    continue;
                }
            } else if (currentLocation == "LockedRoom") {
                if (input == "north") {
                    if (player.getInventory().search("Key") != nullptr) {
                        newRoom = lockedRoom.getExit(input);
                        cout << "You used the key to unlock the door and entered the secret room." << endl;
                    } else {
                        cout << "The door is locked. You need a key to unlock it." << endl;
                        continue;
                    }
                } else {
                    if (lockedRoom.hasExit(input)) {
                        newRoom = lockedRoom.getExit(input);
                        cout << "You moved " << input << " to " << newRoom << endl;
                    } else {
                        cout << "There is no exit in that direction." << endl;
                        continue;
                    }
                }
            } else if (currentLocation == "SecretRoom") {
                if (secretRoom.hasExit(input)) {
                    newRoom = secretRoom.getExit(input);
                } else {
                    cout << "There is no exit in that direction." << endl;
                    continue;
                }
            } else if (currentLocation == "ExitHatch") {
                if (exitHatch.hasExit(input)) {
                    newRoom = exitHatch.getExit(input);
                } else {
                    cout << "There is no exit in that direction." << endl;
                    continue;
                }
            }

            player.move(newRoom);
            cout << "You moved " << input << " to " << newRoom << endl;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
        

        cout << endl;
    }
}

