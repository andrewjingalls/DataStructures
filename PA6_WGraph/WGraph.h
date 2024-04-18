/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA6: Spanning The Gamut
*/

#ifndef WGraph_H
#define WGraph_H

#include <iostream>
#include <limits>
#include <set>
#include <iomanip>
using namespace std;

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public: 
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w);
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j);
  void calcFW();
  void computeMST();
  void setAdj(double** adj);


private:
  double** m_adj; //is there an edge between two vertices and what's the weight of the edge
  double** m_conn; //more general, is there a path between a start and a finish and what's the cost (all parts summed)
  unsigned int N; //nodes in WGraph (fixed)
  
  string m_inputFile;
  double** adjmatrix;
};

#endif