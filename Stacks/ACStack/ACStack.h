//ACStack -> Array Character stack

#ifndef ACSTACK_H
#define ACSTACK_H

class ACStack{
    public:
        ACStack(int iSize);
        ~ACStack();
        void push(char c); //add to the top
        char pop(); //remove & return from the top
        char peek(); //return (but dont remove) top element
        bool isEmpty(); 
        bool isFull(); 
        int size();

    private:
        char* stackArr;
        int theSize;  //number of elements currently in stack
        int maxSize; //max number of elements stack can hold
        int top; //index of current top element in stack


};

#endif