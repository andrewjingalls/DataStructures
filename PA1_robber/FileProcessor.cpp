/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA1: Robber Language Translation
*/
#include "FileProcessor.h"

//Default constructor
FileProcessor::FileProcessor(){
}

//Destructor
FileProcessor::~FileProcessor(){
}

/*Takes in an input and output file. It opens the input first, if it's not open, an error is 
displayed. Then it opens the output file, and if it doesn't open, an error is displayed. 
Then the output file uses html code to make the header and title. The while loop then reads 
each line as input. First it outputs the input file in bold while also storing the translated 
sentences in a variable to display later. After displaying all the sentences, the translatedFile
is then outputted to the html file. Finally both files are closed*/
void FileProcessor::processFile(string inputFile, string outputFile){
    Translator* translator = new Translator();
    ifstream input(inputFile);
    if(!input.is_open()){
        cout << "Error opening input file" << endl;
    }
    ofstream output(outputFile);
    if(!output.is_open()){
        cout << "Error opening output file" << endl;
    }

    output << "<!DOCTYPE html>\n<html>\n<head>\n<title>Rövarspråket Translation</title>\n</head>\n<body>\n";
    string line;
    string translatedFile;
    while(input){
        getline(input, line);
        output << "<p><strong>" << line << "</strong></b>";
        translatedFile += translator->translateEnglishSentence(line);
        translatedFile += "<br><br>";
    }
    output << "<br>";
    output << "<p><i>" << translatedFile << "</p><i>\n" << endl;
    output << "</body>\n</html>\n";

    input.close();
    output.close();

    delete translator;
}