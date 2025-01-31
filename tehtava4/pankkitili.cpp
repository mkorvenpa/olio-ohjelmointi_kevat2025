#include "pankkitili.h"

Pankkitili::Pankkitili(string n)
{
    omistaja = n;
    cout<<"Pankkitili luotu "<<omistaja<<":lle"<<endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double l)
{
    if(l<0){
        return false;
    }
    else{
    saldo=saldo+l;
    cout<<"Pankkitili talletus "<<l<<" tehty"<<endl;
    return true;
    }
}

bool Pankkitili::withdraw(double l)
{
    if(l<0){
        return false;
    }
    if(l>saldo){
        return false;
    }
    else{
        saldo=saldo-l;
        cout<<"Pankkitili nosto "<<l<<" tehty"<<endl;
        return true;
    }
}
