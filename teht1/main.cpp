#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum) {
    srand(time(0));

    int cnum = rand() % maxnum + 1;
    int gnum;
    int attempts = 0;

    cout << "Arvaa luku valilta 1-" << maxnum << ", niin tarkistetaan onko se oikein" << endl;

    do {
        cout << "Arvaa lukua: ";
        cin >> gnum;

         attempts++;

        if(gnum < cnum) {
            cout << "Haetaan suurempaa lukua" << endl;
        } else if(gnum > cnum) {
            cout << "Haetaan pienempaa lukua" << endl;
        } else {
            cout << "Arvasit oikein!" << endl;
        }
    } while(gnum != cnum);

    return attempts;
}

int main() {

    int maxnum;
    cout << "Anna suurin mahdollinen numero ";
    cin >> maxnum;
    int attempts = game(maxnum);
    cout << "Arvasit lukua " << attempts << " kertaa" << endl;

    return 0;
}
