#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int cnum = rand() % 20 + 1;
    int gnum;

    cout << "Arvaa luku valilta 1-20, niin tarkistetaan onko se oikein" << endl;

    do {
        cout << "Arvaa lukua: ";
        cin >> gnum;

        if(gnum < cnum) {
            cout << "Haetaan suurempaa lukua" << endl;
        } else if(gnum > cnum) {
            cout << "Haetaan pienempaa lukua" << endl;
        } else {
            cout << "Arvasit oikein!" << endl;
        }
    } while(gnum != cnum);

    return 0;
}
