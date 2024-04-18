/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include "World.h"
#include "GameParametersReader.h"
#include "Mario.h"
using namespace std;

class Game{
    public:
        Game(GameParametersReader* gameParametersReader);
        void play();
        string moveMarioInGame();
    private:
        World *world;
        GameParametersReader *gameParametersReader;
        Mario *mario;
        bool gameOver;
        ofstream outputFile;
        int positionXWARP;
        int positionYWARP;
};

#endif