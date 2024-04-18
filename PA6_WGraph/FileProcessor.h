/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA6: Spanning The Gamut
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "WGraph.h"
#include <fstream>
#include <sstream>

class FileProcessor{
    public:
        FileProcessor();
        virtual ~FileProcessor();
        WGraph processFile(string inputFile);

    private:
        WGraph m_graph;
        string m_inputFile;
        double** adjmatrix;
};

#endif