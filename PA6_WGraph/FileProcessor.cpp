/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA6: Spanning The Gamut
*/

#include "FileProcessor.h"

//Default constructor
FileProcessor::FileProcessor(){
    m_inputFile = "";
}

//Destructor
FileProcessor::~FileProcessor(){
}

//Processes the input file and returns a WGraph
WGraph FileProcessor::processFile(string input){
    //initializing variables
    int rows = 0;
    int cols = 0;
    string temp;
    string line;
    int num;
    
    //Opening the input file
    ifstream file(input);
    if(file.is_open()){
        //read the first line which is the number of nodes
        getline(file, line);
        if(rows == 0){
            //Convert the string to a double
            num = stod(line);
            //Create a new WGraph with the number of nodes
            m_graph = WGraph(num);

            //Create a new array with values from input file
            adjmatrix = new double*[num];
            for(int i = 0; i < num; ++i){
                adjmatrix[i] = new double[num];
            }
            ++rows;
        }
        
        //Reads the input file and stores the values in the array
        for(int i = 0; i < num; i++){
            //Read the whole file until it reads "END"
            while(getline(file, line) && (line != "END")){ 
                stringstream ss(line);
                for(int j = 0; j < num; j++){
                    //Read each value assign the value into the array, also 
                    //uses a space as a delimiter
                    while(getline(ss, temp, ' ')){
                        adjmatrix[i][j] = stod(temp);
                        break;
                    }
                }
                break;
            }
        }
        //Close the file
        file.close();
        //Set the adjacency matrix to the WGraph
        m_graph.setAdj(adjmatrix);
        //Compute the MST
        m_graph.computeMST();
    }
    //Return the WGraph
    return m_graph;
}