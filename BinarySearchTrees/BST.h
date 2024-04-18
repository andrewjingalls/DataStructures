#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BST{
    public:
        BST();
        virtual ~BST();
        int getSize();
        void insert(T data);
        void remove(T data);
        bool contains(T data);
        void printTreeInOrder();
        void printTreePostOrder();
        T getMin();
        
    private:
        TreeNode<T>* m_root;
        int m_size;
        void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
        void PrintTreeInOrderHelper(TreeNode<T>* subTreeRoot);
        void PrintTreePostOrderHelper(TreeNode<T>* subTreeRoot);
        T getMinHelper(TreeNode<T>* subTreeRoot);
        T getMaxHelper(TreeNode<T>* subTreeRoot);
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
};

template <typename T>
BST<T>::BST(){
    m_root = NULL;
    m_size = 0;
}

template <typename T>
BST<T>::~BST(){
    //free memory
}

template <typename T>
int BST<T>::getSize(){
    return m_size;
}

template <typename T>
void BST<T>::insert(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    insertHelper(m_root, newNode);
    ++m_size;
}

template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        subTreeRoot = newNode; //pointer swap
    }else if(newNode->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
bool BST<T>::contains(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    return containsHelper(m_root, newNode);
}

template <typename T>
bool BST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        return false;
    }else if(newNode->m_data == subTreeRoot->m_data){
        return true;
    }else if(newNode->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
void BST<T>::printTreeInOrder(){
    PrintTreeInOrderHelper(m_root);
}

template <typename T>
void BST<T>::PrintTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        PrintTreeInOrderHelper(subTreeRoot->m_left);
        cout << subTreeRoot->m_data << endl;
        PrintTreeInOrderHelper(subTreeRoot->m_right);
    }
}

template <typename T>
void BST<T>::printTreePostOrder(){
    PrintTreeInOrderHelper(m_root);
}

template <typename T>
void BST<T>::PrintTreePostOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        PrintTreePostOrderHelper(subTreeRoot->m_left);
        PrintTreePostOrderHelper(subTreeRoot->m_right);
        cout << subTreeRoot->m_data << endl;
    }
}

template <typename T>
T BST<T>::getMin(){
    //check if empty
    return getMinHelper(m_root);
}

template <typename T>
T BST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMinHelper(subTreeRoot->m_left);
    }
}

template <typename T>
void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
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
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
   }
   return rightChild;
}

template <typename T>
void BST<T>::remove(T data){
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
        // delete target;  //free the memory

    }
    --m_size;
}



#endif