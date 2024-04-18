/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA5: LazyBST
*/

#ifndef LAZYBST_H
#define LAZYBST_H

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class LazyBST
{
    public:
        LazyBST();
        virtual ~LazyBST();
        int getSize();
        void insert(T data);
        void remove(T data);
        bool contains(T data);
        void printTreeInOrder();
        void printTreePostOrder();
        T getMin();
        bool isTreeBalanced();
        T* sortValues();
        void buildNewTree();
        void rebalance();
        void returnTreeInOrder(void (*func)(T&));
        T* getValues();
        T search(T data);
        
        
        
    private:
        TreeNode<T>* m_root;
        int m_size;
        T* values;
        void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
        void PrintTreeInOrderHelper(TreeNode<T>* subTreeRoot);
        void PrintTreePostOrderHelper(TreeNode<T>* subTreeRoot);
        T getMinHelper(TreeNode<T>* subTreeRoot);
        T getMaxHelper(TreeNode<T>* subTreeRoot);
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
        bool isBalancedHelper(TreeNode<T>* node);
        int getBalanceFactor(TreeNode<T>* node);
        int getHeight(TreeNode<T>* node);
        void sortValuesHelper(TreeNode<T>* subTreeRoot, T* values, int& index);
        TreeNode<T>* buildNewTreeHelper(T* values, int start, int end);
        void returnTreeInOrderHelper(TreeNode<T>* subTreeRoot, void (*func)(T&));
        T searchHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
};

template <typename T>
LazyBST
<T>::LazyBST
(){
    m_root = NULL;
    m_size = 0;
}

template <typename T>
LazyBST
<T>::~LazyBST
(){
    if(m_root != NULL)
        delete m_root; //calls the destructor of the root (which calls the destructor of the children
    //free memory
}

template <typename T>
int LazyBST
<T>::getSize(){
    return m_size;
}

template <typename T>
void LazyBST
<T>::insert(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    insertHelper(m_root, newNode);
    ++m_size;
}

template <typename T>
void LazyBST
<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        subTreeRoot = newNode; //pointer swap
    }else if(newNode->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_right, newNode);
    }
}

//Contains method
template <typename T>
bool LazyBST
<T>::contains(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    return containsHelper(m_root, newNode);
}

//Contains helper that returns a bool if the value is found
template <typename T>
bool LazyBST
<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        return false;   
    }else if(newNode->m_data == subTreeRoot->m_data){
        return true;    //make a new method that does the same thing but returns the node instead of true
    }else if(newNode->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
void LazyBST
<T>::printTreeInOrder(){
    PrintTreeInOrderHelper(m_root);
}

template <typename T>
void LazyBST
<T>::PrintTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        PrintTreeInOrderHelper(subTreeRoot->m_left);
        cout << subTreeRoot->m_data << endl;
        PrintTreeInOrderHelper(subTreeRoot->m_right);
    }
}

//Method for returning the tree in order. 
//Similar to the printTreeInOrder method, but instead of printing the data, 
//it calls a function (which we use later) to return the data whether its a student or faculty object
//This way we can essentially iterate through the tree and return the data in order
template <typename T>
void LazyBST<T>::returnTreeInOrder(void (*func)(T&)){
    returnTreeInOrderHelper(m_root, func);
}

template <typename T>
void LazyBST<T>::returnTreeInOrderHelper(TreeNode<T>* subTreeRoot, void (*func)(T&)){
    if(subTreeRoot != NULL){
        returnTreeInOrderHelper(subTreeRoot->m_left, func);
        func(subTreeRoot->m_data);
        returnTreeInOrderHelper(subTreeRoot->m_right, func);
    }
}

template <typename T>
void LazyBST
<T>::printTreePostOrder(){
    PrintTreeInOrderHelper(m_root);
}

template <typename T>
void LazyBST
<T>::PrintTreePostOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        PrintTreePostOrderHelper(subTreeRoot->m_left);
        PrintTreePostOrderHelper(subTreeRoot->m_right);
        cout << subTreeRoot->m_data << endl;
    }
}

template <typename T>
T LazyBST
<T>::getMin(){
    //check if empty -done
    if(m_root == NULL){
        return NULL;
    }
    return getMinHelper(m_root);
}

//Returns a bool for checking if the tree is balanced
template <typename T>
bool LazyBST<T>::isTreeBalanced(){
    return isBalancedHelper(m_root);
}

//Helper method for checking if the tree is balanced
template <typename T>
bool LazyBST<T>::isBalancedHelper(TreeNode<T>* node){
    //check if empty
    if(node == NULL){
        return false;
    }
    //get balance factor
    int balanceFactor = getBalanceFactor(node);
    //check if balance factor is greater than 1.5 or less than -1.5
    if(balanceFactor > 1.5 || balanceFactor < -1.5){
        return false;
    }else{
        return true;
    }
}

//Method for sorting the tree values into an array
template <typename T>
T* LazyBST<T>::sortValues(){
    T* values = new T[getSize()];
    int index = 0;
    sortValuesHelper(m_root, values, index);
    
    return values;
}

//Helper method compares teh values and adds the values to the array in order
template <typename T>
void LazyBST<T>::sortValuesHelper(TreeNode<T>* subTreeRoot, T* values, int& index){
    if(subTreeRoot != NULL){

        sortValuesHelper(subTreeRoot->m_left, values, index);
        values[index++] = subTreeRoot->m_data;
        sortValuesHelper(subTreeRoot->m_right, values, index);
    }
}

//Getter for the values array
template <typename T>
T* LazyBST<T>::getValues(){
    return values;
}

//Method for building a new tree from the sorted values array
template <typename T>
void LazyBST<T>::buildNewTree(){
    T* values = sortValues();
    
    m_root = buildNewTreeHelper(values, 0, getSize()-1);
    cout << "New Tree Built" << endl;
    delete[] values;

}

//Helper method for building the new tree
template <typename T>
TreeNode<T>* LazyBST<T>::buildNewTreeHelper(T* values, int start, int end){
    //Check if start is greater than end
    if(start > end){
        return NULL;
    }
    //If not, find the middle of the array
    int mid = (start + end) / 2;
    //Create a new node with the middle value
    TreeNode<T>* newNode = new TreeNode<T>(values[mid]);
    //Set the left and right children of the new node
    newNode->m_left = buildNewTreeHelper(values, start, mid - 1);
    newNode->m_right = buildNewTreeHelper(values, mid + 1, end);
    //Return the new node
    return newNode;
}

//Method that calls the sortValues and buildNewTree methods to rebalance the tree
//All in one method
template <typename T>
void LazyBST<T>::rebalance(){
    sortValues();
    buildNewTree();
}

template <typename T>
T LazyBST
<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMinHelper(subTreeRoot->m_left);
    }
}

template <typename T>
T LazyBST
<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_right == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMaxHelper(subTreeRoot->m_right);
    }
}

template <typename T>
void LazyBST
<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    while(target != NULL && target->m_data != key){
        parent = target;
        if(key < target->m_data){
            target = target->m_left;
        }else{
            target = target->m_right;
        }
    }
}

template <typename T>
TreeNode<T>* LazyBST
<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
   }
   return rightChild;
}

template <typename T>
void LazyBST
<T>::remove(T data){
    //check if tree is empty -- UPDATE (move)

    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(data, target, parent);
    if(target == NULL){ //nothing in tree, nothing to do
        return;
    }
    if(target->m_left == NULL && target->m_right == NULL){   //no children, its a leaf. Leaf = both children are null
        if(target == m_root){
            m_root = NULL;
        }else{  //its not the root
            if(target == parent->m_left){
                parent->m_left = NULL;
            }else{
                parent->m_right = NULL;
            }
        }
        // delete target; //free the memory
    }else if(target->m_left != NULL && target->m_right != NULL){ //2 child case
        TreeNode<T>* succ = getSuccessor(target->m_right);
        T value = succ->m_data;
        remove(value);
        target->m_data = value;

    }else{  //1 child case
        TreeNode<T>* child;
        if(target->m_left != NULL){
            child = target->m_left;
        }else{
            child = target->m_right;
        }
        if(target == m_root){
            m_root = child;
        }else{
            if(target == parent->m_left){
                parent->m_left = child;
            }else{
                parent->m_right = child;
            }
        }
        // delete target //free the memory


    }
    --m_size;
}


//Method for getting the balance factor of a node
template <typename T>
int LazyBST<T>::getBalanceFactor(TreeNode<T>* node){
    int leftHeight = getHeight(node->m_left);
    int rightHeight = getHeight(node->m_right);
    int balanceFactor = leftHeight - rightHeight;
    return balanceFactor;
}

//Method for getting the height of a node
template <typename T>
int LazyBST<T>::getHeight(TreeNode<T>* node){
    //Check if node is null
    if(node == NULL){
        return 0;
    }
    //Get the height of the left and right subtrees
    int leftHeight = getHeight(node->m_left);
    int rightHeight = getHeight(node->m_right);
    //Return the height of the larger subtree + 1
    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }else{
        return rightHeight + 1;
    }
}

//Method for searching for a value in the tree
template <typename T>
T LazyBST<T>::search(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    return searchHelper(m_root, newNode);
}

//Search helper method
template <typename T>
T LazyBST<T>::searchHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    //Checks if root is null, if so, throws an error
    if(subTreeRoot == NULL){
        throw runtime_error("Value not found");   
    //Checks if the value is found, if so, returns the value
    }else if(newNode->m_data == subTreeRoot->m_data){
        return subTreeRoot->m_data;
    //Checks if the value is less than the current node, if so, calls the method again with the left child
    }else if(newNode->m_data < subTreeRoot->m_data){
        return searchHelper(subTreeRoot->m_left, newNode);
    //Checks if the value is greater than the current node, if so, calls the method again with the right child
    }else if(newNode->m_data > subTreeRoot->m_data){
        return searchHelper(subTreeRoot->m_right, newNode);
    }
}



#endif