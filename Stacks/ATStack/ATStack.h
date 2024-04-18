#ifndef ATSTACK_H
#define ATSTACK_H

template <typename T>
class ATStack{
    public:
        ATStack(int iSize);
        ~ATStack();
        void push(T e); //add to the top
        T pop(); //remove & return from the top
        T peek(); //return (but dont remove) top element
        bool isEmpty(); 
        bool isFull(); 
        int size();

    private:
        T* stackArr;
        int theSize;  //number of elements currently in stack
        int maxSize; //max number of elements stack can hold
        int top; //index of current top element in stack


};

template <typename T> 
ATStack<T>::ATStack(int iSize){    //constant - O(1)
    stackArr = new T[iSize];
    maxSize = iSize;
    theSize = 0;
    top = -1;   //so i can preincrement later, invalid at first
}

template <typename T>
ATStack<T>::~ATStack(){    //constant - O(1)
    delete[] stackArr;
}

template <typename T>
bool ATStack<T>::isFull(){     //constant - O(1)
    return (theSize == maxSize);
}

template <typename T>
bool ATStack<T>::isEmpty(){    //constant - O(1)
    return (theSize == 0);
}

template <typename T>
int ATStack<T>::size(){    //constant - O(1)
    return theSize;
}

template <typename T>
void ATStack<T>::push(T e){     //constant - O(1) - with no risizing
    //adding ability to resize
    // copy over
    if (isFull()){
        T* temp = new T[maxSize*2];
        for (int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize*=2;
        delete[] stackArr;
        stackArr = temp; //swap pointers
    }
    ++theSize;
    stackArr[++top] = e;
}

template <typename T>
T ATStack<T>::pop(){    //constant - O(1)
    --theSize;
    return stackArr[top--];
}

template <typename T>
T ATStack<T>::peek(){   //constant - O(1)
    return stackArr[top];
}

#endif