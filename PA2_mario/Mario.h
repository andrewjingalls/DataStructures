/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#ifndef MARIO_H
#define MARIO_H

#include <iostream>
#include <string>
#include "GameParametersReader.h"
using namespace std;

class Mario{
    public:
        Mario(GameParametersReader* gameParametersReader);
        virtual ~Mario();
        
        void addCoin();
        void gainPowerLevel();
        void losePowerLevel();
        string moveMario();
        bool fightEnemy(bool win);
        bool fightGoomba();
        bool fightKoopa();
        bool fightBoss();
        

        void gainLife();
        void loseLife();

        int getWinsInRow();
        int getNumLives();
        int getPowerLevel();
        int getNumCoins();
        int getPositionX();
        int getPositionY();
        void setPosition(int x, int y);

    private:
        int numLives;
        int powerLevel;
        int numCoins;
        int positionX;
        int positionY;
        int winsInRow;
};

#endif