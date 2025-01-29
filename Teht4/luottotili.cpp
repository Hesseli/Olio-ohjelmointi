#include "luottotili.h"

Luottotili::Luottotili(string nimi, double raja) : Pankkitili(nimi), luottoRaja(raja) {
    saldo = luottoRaja;
    cout << "Luottotili luotu " << nimi << ":lle" << endl;
}

bool Luottotili:: deposit(double amount) {
    if(amount > 0 && saldo + amount <= luottoRaja) {
        saldo += amount;
        cout << "Luottotili: Maksoit luottoa " << amount << " euroa. Tilin uusi saldo on: " << saldo <<" euroa/" << luottoRaja << " euroa" << endl;
        return true;
    }
    cout << "Luottotili: Luoton maksu epaonnistui" << endl;
    return false;
}

bool Luottotili::withdraw(double amount) {
    if(amount > 0 && (saldo - amount) >= -luottoRaja) {
        saldo -= amount;
        cout << "Luoton nosto onnistui. " << "Luottotilin uusi saldo: "<< saldo << " euroa/" << luottoRaja << " euroa" << endl;
        return true;
    }
    cout << "Luottoa ei voitu myontaa, ole hyva ja tarkista luottoraja" << endl;
    return false;
}

double Luottotili::getLuottoraja() const {
    return luottoRaja;
}
