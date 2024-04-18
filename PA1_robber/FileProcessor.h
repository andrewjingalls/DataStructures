/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA1: Robber Language Translation
*/
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include "Translator.h"
using namespace std;

class FileProcessor{
    public:
        FileProcessor();
        virtual ~FileProcessor();
        void processFile(string inputFile, string outputFile);
};

#endif