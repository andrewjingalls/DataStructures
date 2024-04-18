/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA1: Robber Language Translation
*/
#include "FileProcessor.h"

//Main function takes in two arguments, the input file and the output file and processes the file
int main( int argc, char* argv[]){

    FileProcessor* fileProcessor = new FileProcessor();
    string inputFileName = argv[1];
    string outputFileName = argv[2];
    fileProcessor->processFile(inputFileName, outputFileName);

    delete fileProcessor;
    return 0;
}