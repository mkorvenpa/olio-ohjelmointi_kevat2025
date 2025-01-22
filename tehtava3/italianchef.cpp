#include "italianchef.h"

ItalianChef::ItalianChef(string name) : Chef(name)
{
    cout<<"Italian Chef "<<chefName<<" constructor"<<endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"Italian Chef "<<chefName<<" destructor"<<endl;
}

bool ItalianChef::askSecret(string pw, int a, int b)
{
    if(pw==password){
        cout<<"Password ok!"<<endl;
        makepizza(a,b);
        return true;
    }
    else{
        cout<<"Password incorrect!"<<endl;
        return false;
    }
}

int ItalianChef::makepizza(int a, int b)
{
    flour = a;
    water = b;
    cout<<"Chef "<<chefName<<" with "<<flour<<" flour and "<<water<<" water ";
    int numOfPizza=0;
    while(flour>=5 && water>=5){
        numOfPizza++;
        flour=flour-5;
        water=water-5;
    }
    cout<<"can make "<<numOfPizza<<" pizzas"<<endl;
    return numOfPizza;
}
