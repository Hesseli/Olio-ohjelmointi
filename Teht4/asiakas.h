#ifndef ASIAKAS_H
#define ASIAKAS_H
#include "pankkitili.h"
#include "luottotili.h"
#include <iostream>

class Asiakas {
    public:
        Asiakas(string nimi, double luottoRaja);
        string getNimi();
        void showSaldo();
        bool talletus(double amount);
        bool nosto(double amount);
        bool luotonMaksu(double amount);
        bool luotonNosto(double amount);
        bool tiliSiirto(double amount, Asiakas & vastaanottajaAsiakas);

    private:
        string nimi;
        Pankkitili kayttotili;
        Luottotili luottotili;
};

#endif // ASIAKAS_H
