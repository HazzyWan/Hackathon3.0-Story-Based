#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    bool quitGame = false;

    while (!quitGame) {
    	cout << " $$$$$$$$\\ $$\\   $$\\ $$$$$$$$\\       $$\\       $$$$$$\\   $$$$$$\\ $$$$$$$$\\" << endl;
        cout <<   " \\__$$  __|$$ |  $$ |$$  _____|      $$ |     $$  __$$\\ $$  __$$\\__$$  __|" << endl;
        cout <<     "    $$ |   $$ |  $$ |$$ |            $$ |     $$ /  $$ |$$ /  \\__|  $$ | "  << endl;
        cout <<     "    $$ |   $$$$$$$$ |$$$$$\           $$ |     $$ |  $$ |\\$$$$$$\\    $$ | "  << endl;
        cout <<     "    $$ |   $$  __$$ |$$  __|         $$ |     $$ |  $$ | \\____$$\\   $$ | "  <<endl;
        cout <<     "    $$ |   $$ |  $$ |$$ |            $$ |     $$ |  $$ |$$\\   $$ |  $$ | "  <<endl;
        cout <<     "    $$ |   $$ |  $$ |$$$$$$$$\\       $$$$$$$$\\ $$$$$$  |\\$$$$$$  |  $$ | "  <<endl;
        cout <<     "    \\__|   \\__|  \\__|\\________|      \\________|\\______/  \\______/   \\__| "  <<endl;
                                                                        
        cout << "=============================== Main Menu ===============================" << endl;
        cout << "\t\t\t\t1. Start Game" << endl;
        cout << "\t\t\t\t2. Quit" << endl;
        cout << "\t\t\t\tEnter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();  // Ignore the newline character

        switch (choice) {
            case 1: {
            	system("cls");
                cout << "You awake in a dark room, not knowing what happened to you. As you look around, you see a letter laid on the floor." << endl;
                system("pause");
                string playerName;
                while (playerName.empty()) {
                    cout << "What is your name? " << endl;
                    getline(cin, playerName);

                    if (playerName.empty()) {
                        cout << "Please enter a valid name." << endl;
                    }
                }
                system("pause");
                system("cls");

                // Create a game object and start the game
                Game game(playerName);
                game.run();
                break;
            }
            case 2: {
                quitGame = true;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        if (!quitGame) {
            system("pause");
            system("cls");
        }
    }

    return 0;
}

