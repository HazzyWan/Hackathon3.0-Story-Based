#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    // Prompt the player to enter their name
    cout << "You awake in a dark room, not knowing what happened to you. As you look around, you see a letter laid on the floor." << endl;
    system("pause");
    cout << "What is my name again...? " << endl;
    string playerName;
    getline(cin, playerName);
    system("pause");
    system("cls");

    // Create a game object and start the game
    Game game(playerName);
    game.run();

    return 0;
}
