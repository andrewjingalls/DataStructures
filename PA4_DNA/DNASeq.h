/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA4: Genetic Palindromes
*/
#ifndef DNASEQ_H
#define DNASEQ_H

#include <iostream>
#include <cstdlib>
#include "DblList.h"
using namespace std;

class DNASeq{
    public:
        DNASeq();
        virtual ~DNASeq();
        DNASeq(string data);
        DNASeq(DblList<char>* data);
        DNASeq compliment();
        DNASeq substring(int s, int e);
        bool isGeneticPalindrome(DNASeq* dnaSeq);
        void findSubs();
    private:
        DblList<char>* m_data;

};
#endif