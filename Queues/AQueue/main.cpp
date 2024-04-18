#include "AQueue.h"
using namespace std;

int main(){
    AQueue<char>* theQ = new AQueue<char>(10);
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

    return 0;
}
