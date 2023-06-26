#include <iostream>
#include <string>

using namespace std;

string playerName;

string getPlayerName() {
    string playerName;
    while (playerName.empty()) {
        cout << "Please enter your name: ";
        getline(cin, playerName);
        if (playerName.empty()) {
            cout << "Please enter a valid name." << endl;
        }
    }
    return playerName;
}
void setPlayerName(std::string name) {
    playerName = name;
}

