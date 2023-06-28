#include <iostream>
#include <limits>
#include "Game.h"
#include "Art.h"

using namespace std;

/*void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}*/

int main() {
    bool quitGame = false;

    do {
        Title();
        cout << "=============================== Main Menu ===============================" << endl << endl;
        cout << "\t\t\t    1. Start Game" << endl;
        cout << "\t\t\t    2. Quit" << endl;
        cout << "\t\t\t    3. Last Game History" << endl;

        cout << "\t\t\t    Enter your choice: ";

        string choice;
        getline(cin, choice);
        //clearInputBuffer();

        Game game("");

        if (choice == "1") {
            system("cls");
            cout << "You awake in a dark room, not knowing what happened to you. As you look around, you see a note laid on the floor in \nfront of you." << endl;
            string playerName;
            while (playerName.empty()) {
                system("pause");
                cout << "What is your name? " << endl;
                getline(cin, playerName);

                if (playerName.empty()) {
                    cout << "Please enter a valid name." << endl;
                }
            }
            //system("pause");
            system("cls");

            game.setPlayerName(playerName);
            game.run();
        }
        else if (choice == "2") {
            quitGame = true;
        }
        else if (choice == "3") {
            cout << "Last Game History : \n\n";
            game.readHistory();
            system("pause");
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

        if (!quitGame) {
            //system("pause");
            system("cls");
        }
    } while (!quitGame);

    return 0;
}

