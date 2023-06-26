#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    cout << "You awake in a dark room, not knowing what happened to you. As you look around, you see a letter laid on the floor." << endl;
    system("pause");
    string playerName;
    while (playerName.empty()) {
      cout << "What is your name? "<<endl;
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

    return 0;
}
