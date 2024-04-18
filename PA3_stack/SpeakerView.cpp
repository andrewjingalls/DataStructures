/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA3: Do You See What I See?
*/

#include "SpeakerView.h"

//Default constructor. Initializes the grid in which 
//the heights are stored and creates a stack of doubles.
SpeakerView::SpeakerView(string inputFile){
    double grid;
    int numRows = getRows(inputFile);
    int numCols = getCols(inputFile);
    myStack = new MonoStack<double>(10, 'd');
}

//Destructor. Deletes the stack.
SpeakerView::~SpeakerView(){
   delete myStack;
}

//Computes the number of people that can see in each column
void SpeakerView::computeViewers(string inputFile){
    ifstream file(inputFile);
    string line;
    int count = 0;

    //sets the grid size to the number of rows and columns
    double grid[getCols(inputFile)][getRows(inputFile)];
    int row = 0;

    //reads the input file and stores the heights in the grid
    while(getline(file, line) && line != "END"){
        if(line == "BEGIN")
            continue;
        count++;
        istringstream iss(line);
        int col = 0;
        double height;
       
        while(iss >> height){
            grid[col][row] = height;
            col++;
        }
        row++;
    }

    //reads each column of the grid and pushes the heights of onto the stack
    //and outputs the number of people that can see and their heights
    for(int j = 0; j < getCols(inputFile); j++){
        for(int i = 0; i < getRows(inputFile); i++){
        myStack->push(grid[j][i]);
        }
        cout << "In column " << j << " there are "<< myStack->size() << " people that can see. " << "Their heights are: ";
        while(!myStack->isEmpty()){
            cout << myStack->pop() << ", ";
        }
        cout << "inches." << endl;
    }
}

//Getting the number of rows in the input file, not including the BEGIN and END lines
int SpeakerView::getRows(string inputFile){
    ifstream file(inputFile);
    string line;
    int count = 0;
    while(getline(file, line) && line != "END"){
        if(line == "BEGIN")
            continue;
        count++;
    }
    return count;
}

//Getting the number of columns in the input file.
int SpeakerView::getCols(string inputFile){
    ifstream file(inputFile);
    string line;
    int count = 0;

    getline(file, line);
    getline(file, line);
    istringstream iss(line);
    double height;
    while(iss >> height){
        count++;
    }
    return count;
}