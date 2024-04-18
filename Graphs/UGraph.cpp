#include "UGraph.h"

UGraph::UGraph(){
    m_size = 0;
    m_adj = NULL;
}

UGraph::UGraph(unsigned int sz){
    m_size = sz;
    //allocated sz * sz adj matrix
    m_adj = new VertexID*[sz];
    for(int i = 0; i < m_size; ++i){
        m_adj[i] = new VertexID[sz];
    }

    //initialize values in the adj matrix
    for(int i = 0; i < m_size; ++i){
        for(int j = 0; j < m_size; ++j){
            m_adj[i][j] = 0U; //U is for an unsigned int
        }
    }
}

UGraph::~UGraph(){
    //release memory
    for(int i = 0; i < m_size; ++i){
        delete [] m_adj[i];
    }
}

void UGraph::addEdge(VertexID i, VertexID j){
    if(i < m_size && j < m_size){
        m_adj[i][j] = 1U;
        m_adj[j][i] = 1U;
    }
}

void UGraph::removeEdge(VertexID i, VertexID j){
    if(i < m_size && j < m_size){
        m_adj[i][j] = 0U;
        m_adj[j][i] = 0U;
    }
}

bool UGraph::areAdjacent(VertexID i, VertexID j){
    return (m_adj[i][j] > 0U);
}

void UGraph::printDFS(VertexID i){
    std::stack<VertexID> stk; //stack to help us carry out DFS (Depth First Search)
    std::set<VertexID> visited; //set to keep track of visited nodes
    stk.push(i); //push the starting vertex onto the stack
    while(stk.size() > 0 && visited.size() < m_size){
        VertexID current = stk.top(); //save the vertex at the top of stack
        stk.pop(); 

        //visted.count(current) -> counts num times current is in visted
        //if not in visited, we get 0, this means we have not visited the vertex yet
        if(visited.count(current) != 0){
            continue;
        }
        std::cout << current << std::endl; //print the vertex
        visited.insert(current); //add to vistited so we don't revisit
        for(unsigned int k = 0; k < m_size; ++k){
            /*iterate through the current row of the adj matrix

            check if:
                m_adj[current][k] > 0 -> if this spot in array is 1, theres a connection
                This means it is adjacent to k

                visited.count(k) == 0 -> even if there is a connection at m_adj[current][k]
                if we already visted k, we dont want to visit k again
            */
            if(m_adj[current][k > 0 && visited.count(k) == 0]){
                stk.push(k);
            }
        }
    }
}

void UGraph::printBFS(VertexID i){
    std::deque<VertexID> queue;
    std::set<VertexID> visited;
    queue.push_back(i);
    while(queue.size()>0 && visited.size() < m_size){
        VertexID current = queue.front();
        std::cout << current << std::endl;
        queue.pop_front();
        visited.insert(current);
        for(unsigned int k = 0; k < m_size; ++k){
            if(m_adj[current][k] > 0 && visited.count(k)==0 && !contains(&queue,k)){
                queue.push_back(k);
            }
        }
    }
}
bool UGraph::contains(std::deque<VertexID>* queue, VertexID vi){
    for(int i = 0; i < queue->size(); ++i){
        if(queue->at(i)==vi){
            return true;
        }
    }
    return false;
}

