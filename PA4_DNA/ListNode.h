/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA4: Genetic Palindromes
*/
#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class ListNode{
    public:
        ListNode(T data);
        virtual ~ListNode();
        T m_data;
        ListNode<T>* m_next;    //recursive data structure
        ListNode<T>* m_previous;    //points to instances of itself


};

template <typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = NULL;
    m_previous = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_previous = NULL;
}



#endif