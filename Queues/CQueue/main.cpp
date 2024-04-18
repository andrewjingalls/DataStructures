#include "CQueue.h"
using namespace std;

int main(){
    CQueue<char>* theQ = new CQueue<char>(10); //dynamically allocated on the heap
    theQ->add('P');
    theQ->add('e');
    theQ->add('t');
    theQ->add('e');
    cout << theQ->size() << endl;
    cout << theQ->peek() << endl;
    while(!theQ->isEmpty()){
        cout << theQ->remove() << endl;
    }
    cout << theQ->size() << endl;
    delete theQ;

    theQ = new CQueue<char>(4);
    theQ->add('P');
    theQ->add('e');
    theQ->add('t');
    theQ->add('e');
    cout << theQ->remove() << endl;
    cout << theQ->remove() << endl;
    cout << theQ->size() << endl;
    theQ->add('P');
    theQ->add('a');
    while(!theQ->isEmpty()){
        cout << theQ->remove() << endl;
    }
    cout << theQ->size() << endl;
    delete theQ;
    return 0;
}