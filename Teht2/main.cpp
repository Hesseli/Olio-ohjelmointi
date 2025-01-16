#include "Game.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Anna suurin mahdollinen numero: ";
    int maxNum;
    cin >> maxNum;

    cout << "[DEBUG] Luodaan objekti peliin maxNum=" << maxNum << endl;
    Game game(maxNum);

    game.play();

    cout << "[DEBUG] Peli paattyi" << endl;
    return 0;
}
