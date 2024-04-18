/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA1: Robber Language Translation
*/
#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <iostream>
using namespace std;

class Model{
    public:
        Model();
        virtual ~Model();
        string translateSingleConsonant(char consonant);
        string translateSingleVowel(char vowel);
        bool isVowel(char letter);
        bool isPunctuation(char character);
        
    
};

#endif