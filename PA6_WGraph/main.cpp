/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA6: Spanning The Gamut
*/

#include "FileProcessor.h"
#include <fstream>

int main(int argc, char* argv[]){

    //Input file is the first argument
    string inputFile = argv[1];
    FileProcessor processor = FileProcessor();
    WGraph graph = processor.processFile(inputFile);
    
    return 0;
}