/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA3: Do You See What I See?
*/
#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "MonoStack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

class SpeakerView{
    public:
        SpeakerView(string inputFile);
        virtual ~SpeakerView();
        void computeViewers(string inputFile);
        int getRows(string inputFile);
        int getCols(string inputFile);

    private:
        MonoStack<double>* myStack;

};

#endif