#include "asiakas.h"

Asiakas::Asiakas(string n, double l): kayttotili(n), luottotili(n, l)
{
    nimi = n;
    cout<<"Asiakkuus luotu "<<nimi<<":lle"<<endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout<<"Kayttotilin saldo:"<<kayttotili.getBalance()<<endl;
    cout<<"Luottotilin saldo:"<<luottotili.getCredit()<<endl;
}

bool Asiakas::talletus(double luku)
{
    if(kayttotili.deposit(luku)==true){
        return true;
    }
    else{
        return false;
    }
}

bool Asiakas::nosto(double luku)
{
    if(kayttotili.withdraw(luku)==true){
        return true;
    }
    else{
        return false;
    }
}

bool Asiakas::luotonMaksu(double luku)
{
    if(luottotili.deposit(luku)==true){
        return true;
    }
    else{
        return false;
    }
}

bool Asiakas::luotonNosto(double luku)
{
    if(luottotili.withdraw(luku)==true){
        return true;
    }
    else{
        return false;
    }
}

bool Asiakas::tiliSiirto(double luku, Asiakas &vastaanottaja)
{
    if(nosto(luku)==false){
        return false;
    }
    else{
        vastaanottaja.kayttotili.deposit(luku);
        string vastaNimi = vastaanottaja.getNimi();
        cout<<"Tilisiirto "<<nimi<<":lta "<<vastaNimi<<":lle siirto "<<luku<<endl;
        return true;
    }
}
