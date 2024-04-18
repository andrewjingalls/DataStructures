/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA2: Not So Super Mario Bros.
*/

#ifndef LEVELELEMENT_H
#define LEVELELEMENT_H

#include <iostream>
using namespace std;

class LevelElement{

    public:
        LevelElement();
        virtual ~LevelElement();
        LevelElement(int x, int y, string elementType);
        string getElementType();
    private:
        int x;
        int y;
        string elementType;

};

#endif