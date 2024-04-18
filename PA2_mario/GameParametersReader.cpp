/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#include "GameParametersReader.h"

//Constructor for taking in a file and reading the parameters
GameParametersReader::GameParametersReader(string inputFile, string outputFile){
        ifstream input(inputFile);
        this->outputFile = outputFile;
    if(!input.is_open()){
        cout << "Error opening input file" << endl;
    }
    else{
        //Reads each line of the input file and assigns the values to the correct variables
        string line;
        for(int i = 0; i < 8; i++){
            getline(input, line);
            if(i == 0){
                numberOfLevels = stoi(line);
            }
            else if(i == 1){
                dimensionOfGrid = stoi(line);
            }
            else if(i == 2){
                numberOfLives = stoi(line);
            }
            else if(i == 3){
                PercOfCoins = stoi(line);
            }
            else if(i == 4){
                PercOfNothing = stoi(line);
            }
            else if(i == 5){
                PercOfGoomba = stoi(line);
            }
            else if(i == 6){
                PercOfKoopa = stoi(line);
            }
            else if(i == 7){
                PercOfMushroom = stoi(line);
            }
        }
        input.close();
    }
}

//Destructor
GameParametersReader::~GameParametersReader(){

}

//Getter for the number of levels
int GameParametersReader::getNumberOfLevels(){
        return numberOfLevels;
    }

//Getter for the dimension of the grid
int GameParametersReader::getDimensionOfGrid(){
    return dimensionOfGrid;
    }

//Getter for the number of lives
int GameParametersReader::getNumberOfLives(){
    return numberOfLives;
    }

//Getter for the percentage of coins
int GameParametersReader::getPercOfCoins(){
    return PercOfCoins;
    }

//Getter for the percentage of nothing
int GameParametersReader::getPercOfNothing(){
    return PercOfNothing;
    }

//Getter for the percentage of goombas
int GameParametersReader::getPercOfGoombas(){
    return PercOfGoomba;
    }

//Getter for the percentage of koopas
int GameParametersReader::getPercOfKoopas(){
    return PercOfKoopa;
    }

//Getter for the percentage of mushrooms
int GameParametersReader::getPercOfMushrooms(){
    return PercOfMushroom;
    }

//Getter for the output file
string GameParametersReader::getOutputFile(){
    return outputFile;
    }

