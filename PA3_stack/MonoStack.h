/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA3: Do You See What I See?
*/

#ifndef MONOSTACK_H
#define MONOSTACK_H

template <typename T>
class MonoStack{
    public:
        MonoStack(int iSize, char o);
        ~MonoStack();
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
        char order; //order of stack, 'i' for increasing, 'd' for decreasing


};

//Default constructor. Creates a stack array. Reads in whether its an increasing or decreasing stack.
template <typename T> 
MonoStack<T>::MonoStack(int iSize, char o){   
    stackArr = new T[iSize];
    maxSize = iSize;
    theSize = 0;
    top = -1;   
    
    if(o == 'i'){
        order = 'i';
    }
    else if(o == 'd'){
        order = 'd';
    }
    else{
        order = 'd';
    }
}

//Destructor. Deletes the stack array.
template <typename T>
MonoStack<T>::~MonoStack(){    
    delete[] stackArr;
}

//Returns whether the stack is full or not.
template <typename T>
bool MonoStack<T>::isFull(){    
    return (theSize == maxSize);
}

//Returns whether the stack is empty or not.
template <typename T>
bool MonoStack<T>::isEmpty(){    
    return (theSize == 0);
}

//Returns the size of the stack.
template <typename T>
int MonoStack<T>::size(){    
    return theSize;
}

//Pushes an element onto the stack. 
template <typename T>
void MonoStack<T>::push(T e){     
    //If the stack is increasing, it pops off elements that are smaller than the element being pushed.
    while(!isEmpty() && e > peek() && order == 'i'){ 
        pop();
    }

    //If the stack is decreasing, it pops off elements that are larger than the element being pushed.
    while(!isEmpty()&& e < peek() && order == 'd' ){ 
        pop();
    }

   //If the stack is full, it doubles the size of the stack.
    if (isFull()){
        T* temp = new T[maxSize*2];
        for (int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize*=2;
        delete[] stackArr;
        stackArr = temp; //swap pointers
    }
    //increases the size and adds the element to the top of the stack
    ++theSize;
    stackArr[++top] = e;
}

//Pops an element off the stack.
template <typename T>
T MonoStack<T>::pop(){    
    --theSize;
    return stackArr[top--];
}

//Returns the top element of the stack.
template <typename T>
T MonoStack<T>::peek(){   
    return stackArr[top];
}

#endif