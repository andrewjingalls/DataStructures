/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
#include "Level.h"
#include "GameParametersReader.h"
using namespace std;

class World{
    public:
        World(GameParametersReader* gameParametersReader);
        virtual ~World();
        void nextLevel();
        Level* getCurrentLevel();
        int getNumLevels();
        int getCurrentLevelNum();

    private:
        int level;
        Level **worldLevels;
        Level *currentLevel;

};

#endif