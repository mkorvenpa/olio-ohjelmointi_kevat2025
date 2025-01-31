#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas a1 ("Aapeli", 1000);
    a1.showSaldo();
    a1.talletus(250);
    a1.luotonNosto(150);
    a1.showSaldo();

    Asiakas a2 ("Bertta", 1000);
    a2.showSaldo();

    cout<<a1.getNimi()<<endl;
    a1.showSaldo();
    a1.tiliSiirto(50, a2);
    cout<<a2.getNimi()<<endl;
    a2.showSaldo();
    cout<<a1.getNimi()<<endl;
    a1.showSaldo();

    return 0;
}
