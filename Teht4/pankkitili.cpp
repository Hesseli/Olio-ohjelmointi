#include "pankkitili.h"

Pankkitili::Pankkitili(string nimi) : omistaja(nimi), saldo(0) {
    cout << "Pankkitili luotu " << nimi << ":lle" << endl;
}

double Pankkitili::getBalance() {
    return saldo;
}

bool Pankkitili::deposit(double amount) {
    if(amount > 0) {
        saldo += amount;
        cout << "Pankkitili: talletus " << amount << " euroa tehty. Kayttotilin uusi saldo on: " << saldo << " euroa" << endl;
        return true;
    }
    cout << "Tapahtui virhe talletettaessa rahoja, yrita hetken kuluttua uudelleen" << endl;
    return false;
}

bool Pankkitili::withdraw(double amount) {
    if(amount > 0 && amount <= saldo) {
        saldo -= amount;
        cout << "Pankkitili: nosto " << amount << " euroa tehty. kayttotilin uusi saldo on: " << saldo << " euroa" << endl;
        return true;
    }
    cout << "Nosto epaonnistui, ole hyva ja tarkista tilin saldo" << endl;
    return false;
}
