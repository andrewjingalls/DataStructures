/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA4: Genetic Palindromes
*/
#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string.h>
#include "DNASeq.h"
using namespace std;

class PalindromeFinder{
    public:
        PalindromeFinder();
        virtual ~PalindromeFinder();
        void findPalindromes(string inputFile);
    private:
        DNASeq* dnaSeq;
};
#endif