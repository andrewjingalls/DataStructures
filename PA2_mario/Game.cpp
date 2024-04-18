/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/
#include "Game.h"

//Constructor for creating a new game. Creates a new world and a new mario with the gameParameters
Game::Game(GameParametersReader* gameParametersReader){
    world = new World(gameParametersReader);
    mario = new Mario(gameParametersReader);
    this->gameParametersReader = gameParametersReader;
}

//Play function for playing the full game
void Game::play(){
    //Initializes the action text and next move strings and gets the total number of levels
    string actiontxt = "";
    string nextMove = "";
    int totallevelNum = world->getNumLevels();

    //Opens output file
    ofstream outputFile;
    outputFile.open(gameParametersReader->getOutputFile());

    //Prints the first level to the output file
    outputFile << world->getCurrentLevel()->printLevel() << endl;
    outputFile << "\n";
    

    bool gameOver = false;
    bool didWin;
    //Continue looping until the game is over
    while(!gameOver){
        //Gets the position of mario's x and y
        int posX = mario->getPositionX();
        int posY = mario->getPositionY();

        bool lostFight = false;
        bool win;

        //Gets the element at mario's position and places mario on top
        LevelElement element = world->getCurrentLevel()->getLevelElement(posX, posY);
        string type = element.getElementType();
        world->getCurrentLevel()->setLevelElement(posX, posY, "H");

        //Checks to see if the element is a goomba, if so, it fights the goomba 
        //and sets the results to a string "actiontxt" and calls moveMarioInGame function
        if(type == "g"){
            win = mario->fightGoomba();
            if(win){
                actiontxt = "Mario fought a Goomba and won!";
            }else{
                actiontxt = "Mario fought a Goomba and lost!";
                lostFight = true;
            }
            nextMove = moveMarioInGame();
        }
        //Checks to see if the element is a koopa, if so, it fights the koopa 
        //and sets the results to a string "actiontxt" and calls moveMarioInGame function
        else if (type == "k"){
            win = mario->fightKoopa();
            if(win){
                actiontxt = "Mario fought a Koopa and won!";
            }else{
                actiontxt = "Mario fought a Koopa and lost!";
                lostFight = true;
            }
            nextMove = moveMarioInGame();
        }
        //If element is a coin, adds a coin to mario's wallet, sets actiontext and moves mario
        else if(type == "c"){
            mario->addCoin();
            actiontxt = "Mario collected a coin!";
            nextMove = moveMarioInGame();
        }
        //If element is a mushroom, adds a power level to mario, sets actiontext and moves mario
        else if(type == "m"){
            mario->gainPowerLevel();
            actiontxt = "Mario ate a Mushroom!";
            nextMove = moveMarioInGame();
        }
        //If element is a boss, it fights the boss. If mario wins, he moves to the next level
        //If mario loses, he stays put and continues fighting the boss
        else if(type == "b"){
            win = mario->fightBoss();
            if(win){
                actiontxt = "Mario fought a Boss and won!";
                world->nextLevel();
                nextMove = moveMarioInGame();
            }else{
                actiontxt = "Mario fought a Boss and lost!";
                lostFight = true;
            }
        }
        //If element is a warp pipe, it makes sure mario is not on the last level. If not he warps to the next level.
        //If he is on the last level the space is considered empty. 
        else if(type == "w"){
            if(world->getCurrentLevelNum() < world->getNumLevels()){
                actiontxt = "Mario warped to the next level!";
                world->nextLevel();
            }
            else{
                type == "x";
            }
        }
        //If the space is empty mario just moves on
        else if (type == "x"){
            actiontxt = "The space is empty.";
            nextMove = moveMarioInGame();
        }
        
        //Gets the final variables and sets them to be outputted later
        int winsInRow = mario->getWinsInRow();
        int currLevelNum = world->getCurrentLevelNum();
        int pwrLvl = mario->getPowerLevel();
        int numLives = mario->getNumLives();
        int numCoins = mario->getNumCoins();
    
        //Checks to see if mario is out of lives and the game ends if he is
        if (numLives <= 0){
            numLives = 0;
            didWin = false;
            gameOver = true;
        }
        //Checks if mario made it through all the levels and mario wins if he did
        else if(currLevelNum > totallevelNum){
            currLevelNum = totallevelNum;
            didWin = true;
            gameOver = true;
        }
        
        //Output to the output file showing all the results of the turn
        outputFile << "==============" << endl;
        outputFile << world->getCurrentLevel()->printLevel() << endl;
        outputFile << "Level " << currLevelNum << endl;
        outputFile << "Mario is at position (" << posX << ", " << posY << ")" << endl;
        outputFile << "Mario is at power level " << pwrLvl << endl;
        outputFile << actiontxt << endl;
        outputFile << "Mario has "<< numLives << " lives" << endl;
        outputFile << "Mario has " << numCoins << " coins" << endl;
        outputFile << "Mario has defeated " << winsInRow << " enemies in a row!" << endl;
        outputFile << "Mario will move " << nextMove << endl;
        outputFile << "==============" << endl;

        //If mario wins a fight, the space is set to empty
        if (!lostFight){
           world->getCurrentLevel()->setLevelElement(posX, posY, "x");
        }
        //If mario loses to a goomba, koopa, or a boss, the space is left in tack with the correct type
        if (lostFight && type == "g"){
            world->getCurrentLevel()->setLevelElement(posX, posY, "g");
        }
        if (lostFight && type == "k"){
            world->getCurrentLevel()->setLevelElement(posX, posY, "k");
        }
        if (lostFight && type == "b"){
            world->getCurrentLevel()->setLevelElement(posX, posY, "b");
        }
        
    }
    if(didWin){
        outputFile << "Mario won the game!" << endl;
    }
    else{
        outputFile << "Mario is dead! Game over!" << endl;
    }


    //Closes output file after the game ends
    outputFile.close();
    cout << "Check output file for results!" << endl;
}

//Function for moving mario within the game
string Game::moveMarioInGame(){
    //Gets the direction from the mario class
    string move = mario->moveMario();

    //Gets marios position and the grid size
    int gridSize = gameParametersReader->getDimensionOfGrid();
    int posX = mario->getPositionX();
    int posY = mario->getPositionY();

    int newPosX = posX;
    int newPosY = posY;

    //If the direction is up, down, left, or right, it sets the new position of mario
    //on the grid considering wrapping around the grid
    if(move == "up"){
        
        newPosX = (posX - 1 + gridSize) % gridSize;
    }
    else if(move == "down"){

        newPosX = (posX + 1) % gridSize;
    }
    else if(move == "left"){

        newPosY = (posY -1 + gridSize) % gridSize;
    }
    else if(move == "right"){

        newPosY = (posY + 1) % gridSize;
    }

    //Sets marios new position on the grid
    mario->setPosition(newPosX, newPosY);
   
    return move;
}