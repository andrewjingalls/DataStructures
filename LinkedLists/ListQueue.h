#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H
#include "DblList.h"

template <typename T>
class ListQueue{
    public:
        ListQueue();
        virtual ~ListQueue();
        void add(T data); //add to the back
        T remove(); //remove from the front
        T peek(); //look at the front
        int size();
        bool isEmpty();
    private:
        DblList<T>* m_list;
};

template <typename T>
ListQueue<T>::ListQueue(){
    m_list = new DblList<T>();
}

template <typename T>
ListQueue<T>::~ListQueue(){
    delete m_list;
}

template <typename T>
void ListQueue<T>::add(T data){
    m_list->addBack(data);
}

template <typename T>
T ListQueue<T>::remove(){
    return m_list->removeFront();
}

template <typename T>
T ListQueue<T>::peek(){
    return m_list->get(0);
}

template <typename T>
int ListQueue<T>::size(){
    return m_list->getSize();
}

template <typename T>
bool ListQueue<T>::isEmpty(){
    return m_list->isEmpty();
}

#endif