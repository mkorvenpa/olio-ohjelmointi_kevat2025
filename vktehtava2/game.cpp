#include "game.h"
#include <iostream>

using namespace std;

Game::Game(int a) {
    maxNumber = a;
    cout<<"GAME CONSTRUCTOR: object initialized with "<<a<<" as a maximum value"<<endl;
    srand(time(NULL));
}

Game::~Game()
{
    cout<<"GAME DESTRUCTOR: object cleared from stack memory"<<endl;
}

void Game::play()
{
    int randomNumber = rand()%(maxNumber);
    while(randomNumber==0){
        randomNumber = rand()%(maxNumber);
    }
    cout << "Give your guess between 1-" << maxNumber << endl;
    cin >> playerGuess;
    numOfGuesses = 1;

    while(playerGuess!=randomNumber){
        if(playerGuess<randomNumber){
            cout << "Your guess is too small" << endl;
        }

        if(playerGuess>randomNumber){
            cout << "Your guess is too big" << endl;
        }

        cout << "Give your guess between 1-" << maxNumber << endl;
        cin >> playerGuess;
        numOfGuesses++;
    }

    if(playerGuess==randomNumber){
        cout << "Your guess is right = "<< playerGuess << endl;
        printGameResult();
    }
}

void Game::printGameResult()
{
    cout<<"You guessed the right answer "<<playerGuess;
    cout<<" with "<<numOfGuesses<<" quesses"<<endl;
}
