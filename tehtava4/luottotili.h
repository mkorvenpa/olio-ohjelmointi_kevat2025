#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"

class Luottotili : public Pankkitili
{
public:
    Luottotili(string, double);
    double getCredit();
    bool deposit(double) override;
    bool withdraw(double) override;
protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
