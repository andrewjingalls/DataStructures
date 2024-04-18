#include "ACStack.h"
#include <iostream>
using namespace std;

int main(){
    ACStack myStack(4);
    myStack.push('P');
    myStack.push('e');
    myStack.push('t');
    myStack.push('e');
    myStack.push(' ');
    myStack.push('P');
    myStack.push('a');
    myStack.push('n');

    cout << myStack.peek() << endl;

    while(!myStack.isEmpty()){
        cout << myStack.pop() << endl;
    }

    return 0;
}