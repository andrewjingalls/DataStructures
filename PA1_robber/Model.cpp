/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA1: Robber Language Translation
*/
#include "Model.h"
using namespace std;

//default constructor
Model::Model(){
}

//destructor
Model::~Model(){
}

/*takes in a consonant and returns a new string 
with the consonant, an 'o', and the consonant again*/
string Model::translateSingleConsonant(char consonant){
    string s(3, consonant);
    s[1] = 'o';
    return s;
}

/*Checks to see if an inputed letter is a vowel, if so return true, if not return false*/
bool Model::isVowel(char letter){
    if (letter == 'a' ||letter == 'e' ||letter =='i' ||letter == 'o' ||letter == 'u' ||letter == 'A' ||letter == 'E' ||letter == 'I' ||letter == 'O' ||letter == 'U' || letter == ' ')
        return true;
    else
        return false;
}

/*Checks to see if input character is a punctuation character, if so returns true, if not, returns false*/
bool Model::isPunctuation(char character){
    if (character == '.' || character == ',' || character == '!' || character == '?' || character == ';' || character == ':' || character == '-' || character == '\'')
        return true;
    else
        return false;
}

/*takes in a character and checks to see if it is a vowel or punctuation.
If so, it returns a string with just that character*/
string Model::translateSingleVowel(char vowel){ 
    if (isVowel(vowel) || isPunctuation(vowel)){
        string v(1, vowel);
        return v;
    }
}

