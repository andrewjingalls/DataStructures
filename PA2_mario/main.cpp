/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "GameParametersReader.h"
#include "Level.h"
#include "Game.h"


int main(){
    //a line I found on ChatGPT that seeds the random number generator with
    //the current time to ensure that the random numbers when creating and initializing 
    //a new level are different each time
    srand(static_cast<unsigned int>(time(nullptr)));

    //Gets name of input file from user
    string inputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;

    //Checks if input file exists
    ifstream file(inputFile);
    if (!file.is_open()){
        cout << "Error opening input file" << endl;
        return 0;
    }
    file.close();

    //Gets name of output file from user
    string outputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    //Creates a new GameParametersReader object and a new Game object
    //and calls play function
    GameParametersReader* gameParameters = new GameParametersReader(inputFile, outputFile);
    Game game = Game(gameParameters);
    game.play();
    
   
    delete gameParameters;
    return 0;
}