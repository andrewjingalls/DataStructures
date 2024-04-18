/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA3: Do You See What I See?
*/

#include "SpeakerView.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    string inputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;

    //Checks if input file exists
    ifstream file(inputFile);
    if (!file.is_open()){
        cout << "Error opening input file" << endl;
        return 0;
    }
    file.close();

    SpeakerView speakerView(inputFile);
    speakerView.computeViewers(inputFile);

    return 0;
}