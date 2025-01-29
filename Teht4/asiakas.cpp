#include "asiakas.h"

Asiakas::Asiakas(string nimi, double luottoRaja) : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja) {
    cout << "Asiakkuus luotu " << nimi << ":lle" << endl;
}

string Asiakas::getNimi() {
    return nimi;
}

void Asiakas::showSaldo() {
    cout << "Kayttotilin saldo " << kayttotili.getBalance() << " euroa" << endl;
    cout << "Luottotilin saldo " << luottotili.getBalance() << " euroa/" << luottotili.getLuottoraja() << " euroa" << endl;
}

bool Asiakas::talletus(double amount) {
    return kayttotili.deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return kayttotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    return luottotili.deposit(amount);
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas & vastaanottajaAsiakas) {
    if(amount <= 0) {
        cout << "Siirto epaonnistui" << endl;
        return false;
    }

    if(kayttotili.getBalance() >= amount) {
        cout << getNimi() << endl;
        cout << "Kayttotilin saldo " << kayttotili.getBalance() << " euroa" << endl;
        cout << "Luottotilin saldo " << luottotili.getBalance() << " euroa/" << luottotili.getLuottoraja() << " euroa" << endl;

        if(kayttotili.withdraw(amount)) {
            cout << vastaanottajaAsiakas.getNimi() << endl;
            if(vastaanottajaAsiakas.kayttotili.deposit(amount)) {
                cout << "Siirto onnistui. " << amount << " euroa siirrettiin " << vastaanottajaAsiakas.getNimi() << ":n tilille." << endl;
                cout << "Kayttotilin saldo " << vastaanottajaAsiakas.kayttotili.getBalance() << " euroa" << endl;
                cout << "Luottotilin saldo " << vastaanottajaAsiakas.luottotili.getBalance() << " euroa/" << vastaanottajaAsiakas.luottotili.getLuottoraja() << " euroa" << endl;
                return true;
            } else {
                kayttotili.deposit(amount);
                cout << "Siirto epaonnistui vastaanottavalle tilille." << endl;
                return false;
            }
        }
    } else {
        cout << "Saldo ei riita, ole hyva ja tarkista saldo" << endl;
        return false;
    }

    return false;
}

