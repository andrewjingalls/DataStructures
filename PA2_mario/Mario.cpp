/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#include "Mario.h"
using namespace std;

//Default constructor, sets position to a random number based on the size of the grid
Mario::Mario(GameParametersReader* gameParametersReader){
    numLives = gameParametersReader->getNumberOfLives();
    powerLevel = 0;
    numCoins = 0;
    positionX = rand() % gameParametersReader->getDimensionOfGrid();
    positionY = rand() % gameParametersReader->getDimensionOfGrid();

    
}

//Destructor
Mario::~Mario(){

}

//add one coin to coin count, if 
//coin count is 20, add one life and reset coin count to zero
void Mario::addCoin(){
    numCoins++;
    if(numCoins == 20){
        numLives++;
        numCoins = 0;
    }
}

//increase power level by one, makes sure power level does not exceed 2
void Mario::gainPowerLevel(){
    powerLevel++;
    if(powerLevel >= 2){
        powerLevel = 2;
    }
}

//Decrease power level by one, if power level is zero, mario loses a life
void Mario::losePowerLevel(){
    if (powerLevel > 0){
        powerLevel--;
    }
    else{
        numLives--;
        powerLevel = 0;
    }
    
}

//Choses a random direction to move and returns it as a string
string Mario::moveMario(){
    int m = rand() % 4;
    switch (m){
        case 0:
            return "up";
        case 1:
            return "down";
        case 2:
            return "left";
        case 3:
            return "right";
    }
}

//Adds one life to mario
void Mario::gainLife(){
    numLives++;
}

//Decreases mario's life by one, if mario has zero lives, set lives to zero
//to ensure mario does not have negative lives
void Mario::loseLife(){
    numLives--;
    if (numLives < 0){
        numLives = 0;
    }
}

//If mario wins a fight, wins counter increases by one and if wins counter
//reaches 7, mario gains a life and wins counter is reset to zero
//If mario loses a fight, power level is decreased by one and wins counter
//is reset to zero
bool Mario::fightEnemy(bool win){
    if(win){
        winsInRow++;
        if(winsInRow == 7){
            numLives++;
            winsInRow = 0;
        }
    }
    else{
        losePowerLevel();
        winsInRow = 0;
    }
    return win;
}

//Mario has a 80% chance of beating a goomba
//Returns true if mario wins and calls the fightEnemy function
bool Mario::fightGoomba(){
    bool win = rand() % 100 < 80;
    return fightEnemy(win);
}

//Mario has a 65% chance of beating a koopa
//Returns true if mario wins and calls the fightEnemy function
bool Mario::fightKoopa(){
    bool win = rand() % 100 < 65;
    return fightEnemy(win);
}

//Mario has a 50% chance of beating a boss
//Returns true if mario wins and returns false and loses two power levels if he loses
bool Mario::fightBoss(){
    bool win = rand() % 100 < 50;
    if (win){
        return true;
    }
    else{
        losePowerLevel();
        losePowerLevel();
        return false;
    }
}

//Getter for wins in a row
int Mario::getWinsInRow(){
    return winsInRow;
}

//Getter for number of lives
int Mario::getNumLives(){
    return numLives;
}

//Getter for Mario's power level
int Mario::getPowerLevel(){
    return powerLevel;
}

//Getter for number of coins
int Mario::getNumCoins(){
    return numCoins;
}

//Getter for mario's x position
int Mario::getPositionX(){
    return positionX;
}

//Getter for mario's y position
int Mario::getPositionY(){
    return positionY;
}

//Sets mario's position to the given x and y coordinates
void Mario::setPosition(int x, int y){
    this->positionX = x;
    this->positionY = y;
}