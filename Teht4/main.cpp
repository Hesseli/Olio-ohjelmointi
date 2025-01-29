#include "asiakas.h"

int main() {
    Asiakas asiakas1("Jesse", 1000);

    asiakas1.showSaldo();

    cout << "\n" << endl;

    asiakas1.talletus(500);
    asiakas1.luotonNosto(250);
    asiakas1.nosto(200);
    asiakas1.luotonMaksu(200);

    cout << "\n" << endl;

    asiakas1.showSaldo();

    cout << "\n\n" << endl;

    Asiakas asiakas2("Laura", 3000);

    asiakas2.showSaldo();

    cout << "\n" << endl;

    asiakas2.talletus(0);
    asiakas2.luotonNosto(0);
    asiakas2.nosto(0);
    asiakas2.luotonMaksu(0);

    cout << "\n" << endl;

    asiakas2.showSaldo();

    cout << "\n\n" << endl;

    asiakas1.tiliSiirto(50, asiakas2);


    return 0;
}
