#include "ACStack.h"

ACStack::ACStack(int iSize){    //constant - O(1)
    stackArr = new char[iSize];
    maxSize = iSize;
    theSize = 0;
    top = -1;   //so i can preincrement later, invalid at first
}

ACStack::~ACStack(){    //constant - O(1)
    delete[] stackArr;
}

bool ACStack::isFull(){     //constant - O(1)
    return (theSize == maxSize);
}

bool ACStack::isEmpty(){    //constant - O(1)
    return (theSize == 0);
}

int ACStack::size(){    //constant - O(1)
    return theSize;
}

void ACStack::push(char c){     //constant - O(1) - with no risizing
    //adding ability to resize
    // copy over
    if (isFull()){
        char* temp = new char[maxSize*2];
        for (int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize*=2;
        delete[] stackArr;
        stackArr = temp; //swap pointers
    }
    ++theSize;
    stackArr[++top] = c;
}

char ACStack::pop(){    //constant - O(1)
    --theSize;
    return stackArr[top--];
}

char ACStack::peek(){   //constant - O(1)
    return stackArr[top];
}