#include <iostream>
#include "italianchef.h"

using namespace std;

int main()
{
    Chef chef1 ("Gordon");
    chef1.makeSalad(23);
    chef1.makeSoup(8);

    ItalianChef chef2 ("Mario");
    chef2.makeSalad(15);
    chef2.makeSoup(13);
    string secretPassword;
    cin>>secretPassword;
    chef2.askSecret(secretPassword, 13, 23);
    return 0;
}
