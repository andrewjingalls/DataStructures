/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#include "LevelElement.h"

//Default constructor for an element in the level
LevelElement::LevelElement(){
    x = 0;
    y = 0;
    elementType = "";
}

//Overloaded constructor for an element in the level
//returns the x and y coords and the type of element
LevelElement::LevelElement(int x, int y, string elementTypeParam){
    this->x = x;
    this->y = y;
    this->elementType = elementTypeParam;
}

//Destructor
LevelElement::~LevelElement(){

}

//Getter for the type of the element
string LevelElement::getElementType(){
    return this->elementType;
}
