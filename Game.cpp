#include "Game.h"
#include "Player.h"
#include "Art.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

Game::Game(const string& playerName) :
    player(playerName, "StartRoom"),
    startRoom("The room is consumed by darkness, with only faint traces of light seeping through tiny cracks in the\nancient stone walls. The air hangs heavy with a damp, musty scent, and a chilling coldness\nemanates from the rough, unyielding floor, intensifying the sense of isolation and confinement."),
    treasureRoom("You found a room full of treasures."),
    lockedRoom("You entered a locked room."),
    secretRoom("You discovered a hidden secret room."),
    exitHatch(""),
    archiveRoom("You entered the Archive Room. It is filled with rows of shelves, housing countless dusty books and\nparchments. The air is stale, and the faint smell of decay lingers. It seems like a forgotten place\nholding secrets of the past."),
    hallway("You are in a long, dimly lit hallway. The walls are adorned with old paintings and flickering torches, casting \neerie shadows. You can hear faint whispers echoing through the corridor."),
    morgue("You found a morgue full of dead bodies."),
    fileName("History.txt")
{
    // Add exits to the rooms
    startRoom.addExit("north", "Hallway");
    hallway.addExit("south", "StartRoom");
    hallway.addExit("west", "TreasureRoom");
    hallway.addExit("east", "ArchiveRoom");
    treasureRoom.addExit("east", "Hallway");
    treasureRoom.addExit("south", "LockedRoom");
    lockedRoom.addExit("west", "SecretRoom");
    lockedRoom.addExit("north", "TreasureRoom");
    secretRoom.addExit("east", "LockedRoom");
    secretRoom.addExit("north", "ExitHatch");
    exitHatch.addExit("south", "SecretRoom");
    archiveRoom.addExit("west", "Hallway");
    secretRoom.addExit("south", "TheMorgue");
    morgue.addExit("north", "SecretRoom");

    // Insert items into player's inventory
    player.getInventory().insert(new Item("Note", "Greetings, I know you might be confused as to why you are here. I can only tell you that someone \nwanted you dead. You will be sent to the Gulag tomorrow. Look for clues of the \nperson who did this to you.There is a key you must find in the treasure room. This already puts my life on the line."));

    // Insert items into room's inventory
    treasureRoom.getInventory().insert(new Item("Key", "A golden key"));
    archiveRoom.getInventory().insert(new Item("Book #1", "On the 24th of the Last Seed, prisoner Duncan of Skyrim was captured by the army’s elite \nteam in his house. The prisoner was charged with the murder of General Tullius \nduring the recent riot in the capital of Solitude. The prisoner is sentenced to death by the guillotine.Execution \nwill be held in 2 days, handled by the royal executioner.He will be stationed in the barracks to prepare for execution."));
}

void Game::run() {
    resetHistory();
    // Game loop
    string password;
    bool keyRetrieved = false;  // Flag to track if the key has been retrieved
    bool book1Retrieved = false;

    while (true) {
        // Print player's name, current location, and inventory
        cout << "====================================================================================================================== " << endl;
        cout << "Player Name: " << player.getName() << endl;
        cout << "Current Location: " << player.getCurrentLocation() << endl;
        writeHistory("Player Name : ", player.getName());
        writeHistory("Current Location : ", player.getCurrentLocation());
        cout << "====================================================================================================================== " << endl;
        cout << "Inventory:" << endl;
        player.getInventory().display();
        cout << "====================================================================================================================== " << endl;

        // Display room description
        string currentLocation = player.getCurrentLocation();
        if (currentLocation == "StartRoom") {
            cout << startRoom.getDescription() << endl;
        } else if (currentLocation == "TreasureRoom") {
            Treasure();
            cout << treasureRoom.getDescription() << endl;

            if (!keyRetrieved) {
                  string retrieveKey;
                  bool validInput = false;
 
                  while (!validInput) {
                     cout << "You see a key in the room. Do you want to retrieve it? (yes/no): ";

                     if (!keyRetrieved) {
                        cin >> retrieveKey;
                   } else {
                        retrieveKey = "no";  // Assume the key has already been retrieved
                     }

                     if (retrieveKey == "yes") {
                        Item* retrievedKey = treasureRoom.getInventory().getItem("Key");
                        if (retrievedKey != nullptr) {
                            player.getInventory().insert(retrievedKey);
                            treasureRoom.getInventory().remove(retrievedKey);
                            cout << "You retrieved the key!" << endl;
                            keyRetrieved = true;  // Set the flag to true
                      } else {
                            cout << "There is no key in the room." << endl;
                        }
                        validInput = true;
                    } else if (retrieveKey == "no") {
                        cout << "You decide not to retrieve the key." << endl;
                        validInput = true;
                    } else {
                        cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
                    }
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

            if (password == "VARAN") {
                cout << "Congratulations! You have entered the correct password. You successfully escaped!" << endl;
                break;
            } else {
                cout << "Wrong password. The Exit Hatch remains locked." << endl;//Wrong password will cause the player to choose which direction to explore again.
                system("pause");
                
            }
        } else if (currentLocation == "ArchiveRoom") {
           Shelf();
           cout << archiveRoom.getDescription() << endl;
           cout << "You see a Lost Journal laying on the table." << endl;
           cout << "One of the pages reads: 'Look around closely, for secrets hide in plain sight.'" << endl;

    // Handle the option to read the notes
           string readNotes;
           bool validInput = false;
           while (!validInput) {
             cout << "Do you want to read the notes? (yes/no): ";
             cin >> readNotes;

             if (readNotes == "yes") {
               cout << "You carefully read the notes and find a clue:" << endl;
               cout << "In order to uncover the hidden secret, look closely at the ancient shelf." << endl;
               validInput = true;
               system("pause");
           } else if (readNotes == "no") {
               cout << "You decide not to read the notes for now." << endl;
               validInput = true;
           } else {
               cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
                }
           }

    // Handle the option to retrieve the book
          if (!book1Retrieved) {
           string retrieveBook1;
           validInput = false;

          while (!validInput) {
             cout << "You see an intriguing book in the room. Do you want to take it? (yes/no): ";

              if (!book1Retrieved) {
                cin >> retrieveBook1;
            } else {
                retrieveBook1 = "no";  // Assume the book has already been retrieved
            }

               if (retrieveBook1 == "yes") {
                 Item* retrievedBook1 = archiveRoom.getInventory().getItem("Book #1");
                  if (retrievedBook1 != nullptr) {
                     player.getInventory().insert(retrievedBook1);
                     archiveRoom.getInventory().remove(retrievedBook1);
                     cout << "You retrieved the Book and put it in your inventory!" << endl;
                     book1Retrieved = true;  // Set the flag to true
                 } else {
                     cout << "There is no book in the room." << endl;
                 } 
                 validInput = true;
             } else if (retrieveBook1 == "no") {
                cout << "You decide not to retrieve the book." << endl;
                validInput = true;
             } else {
                cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
             }
           }
         }  
    } else if(currentLocation == "Hallway") {  // Added handling for Hallway
            Hall();
            cout << hallway.getDescription() << endl;
        }else if (currentLocation == "TheMorgue") {
            cout << morgue.getDescription() << endl;
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
                    if (input == "south") {
                        cout << "You see a pile of old papers scattered on the floor, but there is no exit in that direction." << endl;
                        system("pause");
                        system("cls");
                    } else if (input == "west") {
                        cout << "The wall to the west is covered in dirt and grime, with no visible exit." << endl;
                        system("pause");
                        system("cls");
                    } else if (input == "east") {
                        cout << "A solid stone wall blocks your path to the east. There is no exit in that direction." << endl;
                        system("pause");
                        system("cls");
                    } else {
                        cout << "There is no exit in that direction." << endl;
                    }
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
                if (input == "west") {
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
            } else if (currentLocation == "ArchiveRoom") {
                if (archiveRoom.hasExit(input)) {  // Added handling for ArchiveRoom exits
                    newRoom = archiveRoom.getExit(input);
                } else {
                	if (input == "north") {
                       cout << "You see a wall with a large painting depicting a mysterious figure in a cloak. There is no path there." << endl;
                       system("pause");
                       system("cls");
                       continue;
				  } else if (input == "south") {
                       cout << "As you head south, you come across a small reading nook with a comfortable chair and a \nbookshelf filled with ancient tomes." << endl;
                       system("pause");
                       system("cls");
                       continue;
                  } else if (input == "east") {
                       cout << "You notice an ornate wooden door with intricate carvings leading to another room." << endl;
                       system("pause");
                       system("cls");
                       continue;
                  } else {
                    cout << "There is no exit in that direction." << endl;
                    continue;
                }
               }
            } else if (currentLocation == "Hallway") {
                if (hallway.hasExit(input)) {  // Added handling for Hallway exits
                    newRoom = hallway.getExit(input);
                } else {
                	if(input == "north"){
                		Map();
                        system("pause");
                        system("cls");
                		continue;
					}else{
                    cout << "There is no exit in that direction." << endl;
                    continue;
                 }
                }
            } else if(currentLocation == "TheMorgue"){
            	if(morgue.hasExit(input)){
            		newRoom = morgue.getExit(input);
				}else{
					cout<<"There is no exit in that direction."<<endl;
					continue;
				}
			}

            player.move(newRoom);
            cout << "You moved " << input << " to " << newRoom << endl;
            writeHistory("Player moved ", input + " to " + newRoom);
            system("pause");
            system("cls");
        } else {
            cout << "Invalid input. Please enter a valid direction or 'quit'." << endl;
        }
    }
}

void Game::readHistory(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void Game::writeHistory(string action, string detail) {
    ofstream file;
    file.open(fileName, ios::app);
    if (file.is_open()) {
        file << action << detail << endl;
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void Game::resetHistory() {
    ofstream file;
    file.open(fileName);
    if (file.is_open()) {
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

void Game::readHistory() {
    readHistory(fileName);
}

void Game::setPlayerName(const string& playerName) {
    player.setName(playerName);
}
