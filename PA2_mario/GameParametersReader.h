/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#ifndef GAMEPARAMETERSREADER_H
#define GAMEPARAMETERSREADER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class GameParametersReader{
    public:
        GameParametersReader(string inputFile, string outputFile);
        virtual ~GameParametersReader();
        int getNumberOfLevels();
        int getDimensionOfGrid();
        int getNumberOfLives();
        int getPercOfCoins();
        int getPercOfNothing();
        int getPercOfGoombas();
        int getPercOfKoopas();
        int getPercOfMushrooms();
        string getOutputFile();
    private:
        int numberOfLevels;
        int dimensionOfGrid;
        int numberOfLives;

        int PercOfCoins;
        int PercOfNothing;
        int PercOfGoomba;
        int PercOfKoopa;
        int PercOfMushroom;
        string inputFile;
        string outputFile;
};

#endif
