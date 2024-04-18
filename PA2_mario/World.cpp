/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#include "World.h"

int currentLevelNum;

//Constructor for creating a new world. It reads the number of levels from gameParameters
//and creates a new level object for each level in the world
//Then sets the current level to the first level
World::World(GameParametersReader* gameParametersReader){
    currentLevelNum = 1;
    level = gameParametersReader->getNumberOfLevels();
    worldLevels = new Level*[level];
    for (int i = 0; i < level; ++i){
        worldLevels[i] = new Level(gameParametersReader);
    }
    currentLevel = worldLevels[0];
}

//Destructor
World::~World(){

}

//Checks to make sure the current level number is less than the number of levels in the world.
//If so sets the current level to that level number. 
//Finally, increments the current level number
void World::nextLevel(){
    
    if(currentLevelNum < level){
        currentLevel = worldLevels[currentLevelNum];
    }
    currentLevelNum++;
    
}

//Returns the current level
Level* World::getCurrentLevel(){
    return this->currentLevel;
}

//Returns the number of levels in the world
int World::getNumLevels(){
    return level;
}

//Returns the current level number
int World::getCurrentLevelNum(){
    return currentLevelNum;
}


