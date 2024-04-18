#include "MinHeap.h"
#include <iostream>
using namespace std;

int main(){
    MinHeap<int> myHeap(10);
    myHeap.insert(89);
    myHeap.insert(80);
    myHeap.insert(90);
    myHeap.insert(79);
    myHeap.insert(100);
    myHeap.insert(101);
    myHeap.insert(88);

    while(!myHeap.isEmpty()){
        cout << "Min value is: " << myHeap.getMin() << endl;
        myHeap.deleteMin();
    }

    return 0;
}