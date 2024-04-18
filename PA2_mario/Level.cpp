/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#include "Level.h"

//Constructor for creating a new level. It reads the size of the grid
//and creates a 2D array with a size of the parameter. It then initializes the level
Level::Level(GameParametersReader* gameParametersReader){
    //create the 2d array
    this->gridSize = gameParametersReader->getDimensionOfGrid();
    arr2D = new LevelElement *[gridSize];  //outer array - rows
    for (int i = 0; i < gridSize; i++){
        arr2D[i] = new LevelElement[gridSize];  //inner array - columns
    }
    initializeLevel(GameParametersReader(*gameParametersReader));
}

//Destructor
Level::~Level(){
    /*delete the 2d array*/
    for (int i = 0; i < gridSize; ++i){
        delete[] arr2D[i];
    }
    delete[] arr2D;
}

//Loops through the 2D array and adds each element to a string and returns the string at the end,
//displaying the level to the user
string Level::printLevel(){
    /*print the 2d array*/
    string grid;
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
           grid += arr2D[i][j].getElementType() + " ";
        }
        grid += "\n";
    }
    return grid;
}

//First we read in all the percentages given from the game parameters and sets them to variables.
void Level::initializeLevel(GameParametersReader gameParametersReader){
    /*initialize the 2d array*/
    int coinPercentage = gameParametersReader.getPercOfCoins();
    int nothingPercentage = gameParametersReader.getPercOfNothing();
    int goombaPercentage = gameParametersReader.getPercOfGoombas();
    int koopaPercentage = gameParametersReader.getPercOfKoopas();
    int mushroomPercentage = gameParametersReader.getPercOfMushrooms();
    int totalPercentage = coinPercentage + nothingPercentage + goombaPercentage + koopaPercentage + mushroomPercentage;
    int randomNum;
    int x;
    int y;

   
    //We loop through the 2D array and given the percentages from our gameparameters,
    //we set the elements in the array to the correct type based on said parameters.
    //c = coin, x = nothing, g = goomba, k = koopa, m = mushroom
    for (int i = 0; i < gridSize; i++){
        for (int j = 0; j < gridSize; j++){
            randomNum = rand() % totalPercentage;
            if(randomNum < coinPercentage){
                arr2D[i][j] = LevelElement(i, j, "c");
            }
            else if(randomNum < coinPercentage + nothingPercentage){
                arr2D[i][j] = LevelElement(i, j, "x");
            }
            else if(randomNum < coinPercentage + nothingPercentage + goombaPercentage){
                arr2D[i][j] = LevelElement(i, j, "g");
            }
            else if(randomNum < coinPercentage + nothingPercentage + goombaPercentage + koopaPercentage){
                arr2D[i][j] = LevelElement(i, j, "k");
            }
            else{
                arr2D[i][j] = LevelElement(i, j, "m");
            }
            
        }
    }
    //Then we randomly set a boss in the level
    x = rand() % gridSize;
    y = rand() % gridSize;
    arr2D[x][y] = LevelElement(x, y, "b");
    
    //And we set a warp pipe to a randomly assigned location
    x = rand() % gridSize;
    y = rand() % gridSize;
    arr2D[x][y] = LevelElement(x, y, "w");
}

//Getter for the level element at a given x and y coordinate
LevelElement Level::getLevelElement(int x, int y){
    return arr2D[x][y];
}

//Setter for the level element at a given x and y coordinate and element type
void Level::setLevelElement(int x, int y, string type){
    arr2D[x][y] = LevelElement(x, y, type);
}
