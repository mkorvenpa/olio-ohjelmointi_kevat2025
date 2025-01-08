#include <iostream>
#include <ctime>

using namespace std;

int game(int maxnum);

int main()
{
    int arvausMaara = game(40);
    cout << "Arvausten maara oli " << arvausMaara << endl;
    return 0;
}

int game(int maxnum){
    srand(time(NULL));
    int luku = rand()%(maxnum);
    while(luku==0){
        luku = rand()%(maxnum);
    }
    cout << "Arvaa luku (1-" << maxnum << ")" << endl;
    int arvaus;
    cin >> arvaus;
    int arvausMaara = 1;

    while(arvaus!=luku){
        if(arvaus<luku){
            cout << "Luku on suurempi" << endl;
        }

        if(arvaus>luku){
            cout << "Luku on pienempi" << endl;
        }

        cout << "Arvaa luku uudestaan (1-" << maxnum << ")" << endl;
        cin >> arvaus;
        arvausMaara++;
    }

    if(arvaus==luku){
        cout << "Oikea vastaus!" << endl;
    }

    return arvausMaara;
}
