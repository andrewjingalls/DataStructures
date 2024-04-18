/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "GameParametersReader.h"
#include "LevelElement.h"
using namespace std;

class Level{
    public:
        Level(GameParametersReader* gameParametersReader);
        virtual ~Level();

        string printLevel();
        void initializeLevel(GameParametersReader gameParametersReader);
        LevelElement getLevelElement(int x, int y);
        void setLevelElement(int x, int y, string type);

    private:
        LevelElement **arr2D;
        int gridSize;
        



};

#endif