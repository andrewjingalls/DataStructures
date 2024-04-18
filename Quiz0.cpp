#include <iostream>

using namespace std;

int main(){

    cout << "Enter the length of the array: " << endl;
    int n = 0;
    cin >> n;

    int* arr = new int[n];  //dynamically allocated an array of size n
    for(int i = 0; i < n; ++i){
        arr[i] = i*2;
    }

    //print to varify
    cout << "--printing array --" << endl;
    for(int i = 0; i < n; ++i){
        cout << arr[i] << endl;
    }

    delete[] arr;   //deallocate the array

    return 0;
}