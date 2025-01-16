#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int maxNum) : maxNumber(maxNum), playerGuess(0), randomNumber(0), numOfGuesses(0) {
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
}

Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play() {
    cout << "Arvaa luku valilta 1-" << maxNumber << ", niin tarkistetaan onko se oikein" << endl;

    do {
        cout << "Arvaa lukua: ";
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "Haetaan suurempaa lukua" << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Haetaan pienempaa lukua" << endl;
        } else {
            cout << "Arvasit oikein!" << endl;
        }
    } while (playerGuess != randomNumber);

    printGameResult();
}

void Game::printGameResult() {
    cout << "Oikea luku oli: " << randomNumber << endl;
    cout << "Arvasit lukua " << numOfGuesses << " kertaa" << endl;
}
