#include "BST.h"
int main(){
    BST<int> tree;
    tree.insert(4);
    tree.insert(10);
    tree.insert(2);
    tree.insert(3);
    cout << "The size is: " << tree.getSize() << endl;
    cout << "Print Tree In Order:" << endl;
    tree.printTreeInOrder();
    cout << endl;
    cout << "Print Tree Post Order:" << endl;
    tree.printTreePostOrder();
    cout << endl;
    cout << tree.contains(10) << endl;
    cout << tree.contains(5) << endl;
    cout << endl;
    cout << "Testing extrema" << endl;
    // cout << tree.getMax() << endl;
    cout << tree.getMin() << endl;
    return 0;
}