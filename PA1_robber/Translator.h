/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA1: Robber Language Translation
*/
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Model.h"
#include <iostream>
#include <string>
using namespace std;

class Translator{
    public:
        Translator();
        virtual ~Translator();
        string translateEnglishWord(string word);
        string translateEnglishSentence(string sentence);

    private:
        Model* m_model;
};

#endif