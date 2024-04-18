#ifndef CQueue_H
#define CQueue_H
#include <iostream>

template <typename T>
class CQueue{
    public:
        CQueue(int size);
        virtual ~CQueue();
        bool isEmpty();
        bool isFull();
        void add(T data); //add to the back
        T remove(); //remove from the front
        T peek(); //look at but don't remove the item at the front
        int size();
    private:
        int numItems;
        int front;
        int back;
        int maxSize;
        T* arr; //where data is stored
};

template <typename T>
CQueue<T>::CQueue(int size){ //constant
    maxSize = size;
    numItems = 0;
    front = 0;
    back = -1; 
    arr = new T[maxSize];
}

template <typename T>
CQueue<T>::~CQueue(){ //constant
    //std::cout << "I'm freeing up memory!" << std::endl;
    delete[] arr;
}

template <typename T>
bool CQueue<T>::isEmpty(){ //constant
    return (numItems == 0);
}

template <typename T>
bool CQueue<T>::isFull(){ //constant
    return (numItems == maxSize);
}

template <typename T>
int CQueue<T>::size(){ //constant
    return numItems;
}

template <typename T> 
void CQueue<T>::add(T data){ //constant
    if(back == maxSize - 1){ //make sure it's not full
        back = -1;
    }
    arr[++back] = data;
    ++numItems;
}

template <typename T>
T CQueue<T>::remove(){ //constant
    T ret = arr[front];
    ++front;
    --numItems;
    if(front == maxSize){
        front = 0;
    }
    return ret;
}

template <typename T>
T CQueue<T>::peek(){ //constant
    T ret = arr[front];
    return ret;
}

#endif

