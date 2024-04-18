/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA4: Genetic Palindromes
*/
#include "PalindromeFinder.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    //Gets input file name from user
    string inputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;

    //Checks if input file exists
    ifstream file(inputFile);
    if (!file.is_open()){
        cout << "Error opening input file" << endl;
        return 0;
    }

    //Creates a PalindromeFinder object and calls findPalindromes
    PalindromeFinder* palindromeFinder = new PalindromeFinder();
    palindromeFinder->findPalindromes(inputFile);
    
    //Closes input file
    file.close();
    return 0;
}