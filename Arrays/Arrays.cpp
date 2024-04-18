#include <iostream>
using namespace std;


void printArray(int array[], int length){   //int arr[] is passing a pointer, compiler treats it as int* arr[]
    for(int i = 0; i < length; ++i){
        cout << array[i] << endl;
    }
}

void printArray2D(int** array2D, int row, int col){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cout << array2D[i][j] << endl;
        }
    }
}


int main(){
    //statically allocated arrays
    //declare array-->  type name[size]
    int arr1[3]; //array of ints with size 3
    arr1[0] = 10;
    arr1[1] = 20;   //adding values to array
    arr1[2] = 30;

    // printArray(arr1, 3);
    // cout << endl;

    // for(int i =0; i < 3; ++i){  //print elements in array
    //     cout << arr1[i] << endl;
    // }

    // int arr2[4];
    // for(int i =0; i < 4; ++i){  //print elements in array
    //     cout << arr1[i] << endl;
    // }

    // int arr2[5] = {5, 10, 15, 20, 25};
    // for(int i =0; i < 5; ++i){  //print elements in array
    //     cout << arr2[i] << endl;
    // }

    // int arr3[10];
    // printArray(arr3, 10);

    int* arr4 = new int[5]; //dynamically allocated array, array of ints size 5
    for(int i = 0; i < 5; ++i){
        arr4[i] = i * 2;
    }

    printArray(arr4, 5);

    delete[] arr4;  //must delete array if we use new(), bc no garbage collector in c++

    //allocate 2D array
    int** arr2D = new int*[3];  //outer array - rows
    for (int i = 0; i < 3; ++i){
        arr2D[i] = new int[4];  //inner array - columns
    }

    //initialize
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 4; ++j){
            arr2D[i][j] = i*2;
        }
    }

    //delete 
    for (int i = 0; i < 3; ++i){
        delete[] arr2D[i];  //delete inner array - rows
    }
    delete[] arr2D; // delete outer array - columns

}