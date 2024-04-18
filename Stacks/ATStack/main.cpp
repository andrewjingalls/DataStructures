#include "ATStack.h"
#include <iostream>
using namespace std;

int main(){
    ATStack<char> myStack(10);
    myStack.push('P');
    myStack.push('e');
    myStack.push('t');
    myStack.push('e');

    cout << myStack.peek() << endl;

    while(!myStack.isEmpty()){
        cout << myStack.pop() << endl;
    }

    cout << endl;

    ATStack<int> myStack2(10);
    myStack2.push(2);
    myStack2.push(4);
    myStack2.push(6);
    myStack2.push(8);

    cout << myStack2.peek() << endl;

    while(!myStack2.isEmpty()){
        cout << myStack2.pop() << endl;
    }

    return 0;
}