#include <iostream>
using namespace std;

int main(){
    /*Print a 2d array with a dash in each index*/
    int** arr2D = new int*[5];  //outer array - rows
    for (int i = 0; i < 5; ++i){
        arr2D[i] = new int[5];  //inner array - columns
    }
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
            arr2D[i][j] = 0;
        }
    }

    arr2D[4][3] = 2;

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
           cout << arr2D[i][j];
        }
        cout << endl;
    }



    
    // char** arr2D = new char*[5];  //outer array - rows
    // for (int i = 0; i < 5; ++i){
    //     arr2D[i] = new char[5];  //inner array - columns
    // }
    // for (int i = 0; i < 5; ++i){
    //     for (int j = 0; j < 5; ++j){
    //         arr2D[i][j] == "-";
    //     }
    // }
    // cout << arr2D <<endl;
    return 0;
}