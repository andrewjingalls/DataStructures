#ifndef UGRAPH_H
#define UGRAPH_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>

/* - an implementation of an unweighted, undirected graph
   - with adjacency matrix
   - fixed size */

typedef unsigned int VertexID; //creating a type name called VertexID that is the same as an unsigned int

class UGraph{
    public:
        UGraph();
        UGraph(unsigned int sz);
        virtual ~UGraph();
        void addEdge(VertexID i, VertexID j);
        void removeEdge(VertexID i, VertexID j);
        bool areAdjacent(VertexID i, VertexID j);
        void printDFS(VertexID i); //print path of DFS starting at i
        void printBFS(VertexID i); //print path of BFS starting at i

    private:
        VertexID** m_adj;
        unsigned int m_size; //nodes in the UGraph (fixed)

};

#endif