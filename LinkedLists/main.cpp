#include <iostream>
#include "DblList.h"
#include "ListQueue.h"

using namespace std;

int main(){
/*
    DblList<int> myList;
    for (int i = 0; i < 10; ++i){
        myList.add(i,i);
    }

    myList.add(5,222);
    myList.addFront(14);
    myList.addBack(28);
    for (int i = 0; i < myList.getSize(); ++i){
        cout << myList.get(i) << endl;
    }
    */
   ListQueue<int> lq;
   lq.add(20);
    lq.add(30);
    lq.add(40);
    lq.remove();
    while(!lq.isEmpty()){
        cout << lq.remove() << endl;
    }
    cout << "Size: " << lq.size() << endl;

    return 0;
}