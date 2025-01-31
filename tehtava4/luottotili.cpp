#include "luottotili.h"

Luottotili::Luottotili(string n, double l) : Pankkitili(n)
{
    luottoRaja = l;
    cout<<"Luottotili luotu "<<omistaja<<":lle, luottoraja "<<luottoRaja<<endl;
}

double Luottotili::getCredit()
{
    return luottoRaja;
}

bool Luottotili::deposit(double l)
{
    if(l<0 || saldo+l>0){
        return false;
    }
    else{
        saldo+=l;
        luottoRaja+=l;
        cout<<"Luottotili talletus "<<l<<" tehty"<<endl;
        return true;
    }
}

bool Luottotili::withdraw(double l)
{
    if((luottoRaja-l)<0){
        return false;
    }
    else{
        saldo-=l;
        luottoRaja-=l;
        cout<<"Luottotili nosto "<<l<<" tehty, luottoa jaljella "<<luottoRaja<<endl;
        return true;
    }
}


