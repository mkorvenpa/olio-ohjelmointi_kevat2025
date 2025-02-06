#include "notifikaattori.h"

Notifikaattori::Notifikaattori()
{
    cout<<"Luodaan notifikaattori"<<endl;
}

void Notifikaattori::lisaa(Seuraaja * o)
{
    o->next = seuraajat;
    seuraajat = o;
    cout<<"Notifikaattori lisaa seuraajan "<<o->getNimi()<<endl;
}

void Notifikaattori::poista(Seuraaja * o)
{
    Seuraaja * p = seuraajat;
    while(p->next!=o){
        p=p->next;
    }
    p->next=o->next;
    cout<<"Notifikaattori poistaa seuraajan "<<o->getNimi()<<endl;
}

void Notifikaattori::tulosta()
{
    cout<<"Notifikaattorin seuraajat:"<<endl;
    Seuraaja * o = seuraajat;
    while(o != nullptr){
        cout<<"Seuraaja "<<o->getNimi()<<endl;
        o=o->next;
    }
}

void Notifikaattori::postita(string n)
{
    cout<<"Notifikaattori postittaa viestin: "<<n<<endl;
    Seuraaja * o = seuraajat;
    while(o != nullptr){
        cout<<"Seuraaja "<<o->getNimi()<<" saa viestin: ";
        o->paivitys(n);
        o=o->next;
    }
}
