#ifndef DBLLIST_H
#define DBLLIST_H

#include "ListNode.h"

template <typename T>
class DblList{
    public:
        DblList();
        virtual ~DblList();
        void addFront(T data);
        void addBack(T data);
        void add(int pos, T data);
        T removeFront();
        T removeBack();
        T remove(int pos);
        bool isEmpty();
        int getSize();
        T get(int pos);
    private:
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;
};

template <typename T>
DblList<T>::DblList(){
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template <typename T>
DblList<T>::~DblList(){
    //to do - free memory - loop through the list and delete all nodes
    // while(!isEmpty()){   //maybe will work
    //     removeFront();
    // }
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template <typename T>
int DblList<T>::getSize(){  //constant big O runtime - O(1)
    return m_size;
}

template <typename T>
bool DblList<T>::isEmpty(){ //constant big O runtime - O(1)
    return m_size == 0;
}

template <typename T>
void DblList<T>::addFront(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty){
        m_front->m_previous = newNode;
        newNode->m_next = m_front;
    }
    else{   //the list is empty
        m_back = newNode;
    }
    m_front = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::addBack(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty){
        m_back->m_next = newNode;
        newNode->m_previous = m_back;
    }
    else{   //list is empty
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template <typename T>
void DblList<T>::add(int pos, T data){  //linear big O runtime - O(n)
    if(isEmpty()){
        addFront(data);
    }
    else if(pos == 0){
        addFront(data);
    }
    else if(pos >= m_size){
       addBack(data);
    }
    else{
        ListNode<T>* current = m_front;
        int cPos = 0;
        while(cPos != pos){
            current = current->m_next;
            ++cPos;
        }
        ListNode<T>* newNode = new ListNode<T>(data);
        current->m_previous->m_next = newNode;
        newNode->m_previous = current->m_previous;
        current->m_previous = newNode;
        newNode->m_next = current;
        ++m_size;
    }
}

template <typename T>
T DblList<T>::removeFront(){    //constant big O runtime - O(1)
    T data;
    data = m_front->m_data;
    //make sure not empty
    if(m_size == 1){
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currFront = m_front;
        m_front = m_front->m_next;
        m_front->m_previous = NULL;
        delete currFront;
    }
    --m_size;
    return data;

}

template <typename T>
T DblList<T>::removeBack(){     //constant big O runtime - O(1)
    T data;
    data = m_back->m_data;
    //make sure not empty
    if(m_size == 1){
       delete m_back; //could use m_front, bc back and front point to the same place
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currBack = m_back;
        m_back = m_back->m_previous;
        m_back->m_next = NULL;
        delete currBack;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::remove(int pos){  //linear big O runtime - O(n)
    //make sure not empty
    T data;
    if(pos == 0){
        data = removeFront();
    }else if(pos >= m_size){
        data = removeBack();
    }else{
        ListNode<T>* current = m_front;
        int cPos = 0;
        while(cPos != pos){
            current = current->m_next;
            ++cPos;
        }
        data = current->m_data;
        current->m_previous->m_next = current->m_next;
        current->m_next->m_previous = current->m_previous;
        delete current;
        --m_size;
    }
    return data;
}

template <typename T>
T DblList<T>::get(int pos){    //linear big O runtime - O(n)
    //TODO - make sure position is in range
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos != pos){
        current = current->m_next;
        ++cPos;
    }
    return current->m_data;
}




#endif