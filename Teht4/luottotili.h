#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"
#include <iostream>

class Luottotili:public Pankkitili
{
    public:
        Luottotili(string nimi, double raja);
        ~Luottotili() override {}

        bool deposit(double amount) override;
        bool withdraw(double amount) override;

        double getLuottoraja() const;

    protected:
        double luottoRaja;
};

#endif // LUOTTOTILI_H
