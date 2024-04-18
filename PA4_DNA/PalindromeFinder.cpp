/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA4: Genetic Palindromes
*/
#include "PalindromeFinder.h"

//Default constructor
PalindromeFinder::PalindromeFinder(){ 
}

//Destructor
PalindromeFinder::~PalindromeFinder(){
}

//Takes an input file name as a parameter and reads the file line by line
void PalindromeFinder::findPalindromes(string inputFile){
    //Checks if file exists
    ifstream file(inputFile);
    if (!file.is_open()){
        cout << "Error opening input file" << endl;
    }
    string line;
    //Loops through each line until it reads "END"
    //Creates a DNASeq object for each line, checks its compliment, 
    //and checks if it is a genetic palindrome
    //Then it finds all the possible palindromes within the sequence called findSubs()
    while(getline(file, line) && line != "END"){
        DNASeq* dnaSeq = new DNASeq(line);
        dnaSeq->compliment();
        if(dnaSeq->isGeneticPalindrome(dnaSeq)){
            cout << " - Genetic palindrome!" << endl;
        }else{
            cout << " - Not a genetic palindrome" << endl;
        }
        dnaSeq->findSubs();
    }
    file.close();
}