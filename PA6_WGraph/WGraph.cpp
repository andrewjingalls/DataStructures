/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA6: Spanning The Gamut
*/

#include "WGraph.h"

WGraph::WGraph(){
  N = 0;
  m_adj = NULL;
  m_conn = NULL;
}

WGraph::WGraph(unsigned int sz){
  N = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < N; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max(); //essentially infinity
      m_conn[i][j] = std::numeric_limits<double>::max();
    }
  }
}

WGraph::~WGraph(){
  //release memory
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < N && j < N){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
}

void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < N && j < N){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}


void WGraph::calcFW(){ //runtime complexity O(v^3)
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }
  for(int im = 0; im < N; ++ im){ //intermediate points --> transitive closure
    for(int source = 0; source < N; ++source){ //source = starting point
      for(int sink = 0; sink <N; ++sink){ //sink = ending point
        if(source == sink){
          continue;
        }else if(m_conn[source][im] != std::numeric_limits<double>::max() &&
          m_conn[im][sink] != std::numeric_limits<double>::max() &&
          m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
           m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }
      }
    }
  }
}

double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j]; //constant
}

void WGraph::computeMST(){
  //Make a new array with the cheapest values
  double* cheapest = new double[N];
  double minValue = 100.0;
  double sum = 0.0;
  int column = 0;
  
  //iterates through the array and finds the cheapest value
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      //if the value is less than the minValue and not 0, then it is the new minValue
      if((adjmatrix[i][j] < minValue) && (adjmatrix[i][j] != 0)){
        minValue = adjmatrix[i][j];
      }
    }
    //adds cheapest value to the array
    cheapest[column] = minValue;
    ++column;
    //adds the cheapest value to the sum
    sum += minValue;
    //resets the minValue
    minValue = 100.0;
    

    
  }
  //Prints MST Cost
  cout << "The MST Cost is: " << sum << endl;


  //Make an adjacency matrix with the cheapest values
  double** newAdj = new double*[N];
  for(int i = 0; i < N; ++i){
    newAdj[i] = new double[N];
    std::fill_n(newAdj[i], N, 0.0);
  }

  int a = 0;
  //Itereates through new adjacency matrix and sets the values with the cheapest values
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      //if the value is equal to the cheapest value, then it is set to the new adjacency matrix
      if(cheapest[a] == adjmatrix[i][j]){
        newAdj[i][j] = cheapest[a];
        break;
        //value set to 0.0 if it is not the cheapest value
      }else{
        newAdj[i][j] = 0.0;
      }
    }
    ++a;
  }

  //Print out the new adjacency matrix
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(j == 0){
        if(newAdj[i][j] == 0.0){
          cout << "0.0" << ' ';
        }else{
          //Makes sure the value is printed as a double with one decimal place
          cout << fixed << setprecision(1) << newAdj[i][j] << ' ';
        }
      }else if(j == N-1){
        if(newAdj[i][j] == 0.0){
          cout << "0.0" << endl;
        }else{
          //Makes sure the value is printed as a double with one decimal place
          cout << fixed << setprecision(1) << newAdj[i][j] << endl;
        }
      }else{
        if(newAdj[i][j] == 0.0){
          cout << "0.0" << ' ';
        }else{
          //Makes sure the value is printed as a double with one decimal place
          cout << fixed << setprecision(1) << newAdj[i][j] << ' ';
        }
      }
    }
  }


}

//Setter for the adjacency matrix
void WGraph::setAdj(double** adj){
  adjmatrix = adj;
}
