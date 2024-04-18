#ifndef AQUEUE_H
#define AQUEUE_H
#include <iostream>

template <typename T>
class AQueue{
    public:
        AQueue(int iSize);
        ~AQueue();
        bool isEmpty();
        bool isFull();
        void add(T data); //add to the back
        T remove(); //remove from the front
        T peek(); //returns but does not remove the first element
        int size();

    private:
        T* arr;
        int maxSize;
        int front;
        int back;
        int theSize; //how many items are in the queue

};

template <typename T>
AQueue<T>::AQueue(int iSize){
    maxSize = iSize;
    theSize = 0;
    front = 0;
    back = -1;
    arr = new T[maxSize];
}

template <typename T>
AQueue<T>::~AQueue(){
    std::cout << "I'm freeing up memory!" << std::endl;
    delete[] arr;
}

template <typename T>
bool AQueue<T>::isFull(){ //constant - O(1)
    return (theSize == maxSize);
}

template <typename T>
bool AQueue<T>::isEmpty(){ //constant - O(1)
    return (theSize == 0);
}

template <typename T>
int AQueue<T>::size(){ //constant - O(1)
    return theSize;
}

template <typename T>
void AQueue<T>::add(T data){ //constant - O(1)
    arr[++back] = data;
    ++theSize;
}

template <typename T>
T AQueue<T>::remove(){ //constant - O(1)
    T ret = arr[front];
    ++front;
    --theSize;
    return ret;
}

template <typename T>
T AQueue<T>::peek(){ //constant - O(1)
    T ret = arr[front];
    return ret;
}

#endif