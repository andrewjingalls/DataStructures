#include <iostream>
using namespace std;

int simpleSearch(int* arr, int lenn, int key){
    int idx = -1;
    //int comparisons = 0;
    for(int i = 0; i < lenn; ++i){
        //++comparisons;
        if(arr[i] == key){
            idx = i;
            break;
        }
    }
    return idx;
}


int binarySearch(int* arr, int lenn, int key){
    int idx = -1;
    int right = lenn;
    int left = 0;
    //int comparisons = 0;
    while(right >= left){
        int middle = (right+left)/2;
        //++comparisons;
        if(arr[middle] == key){
            idx = middle;
            break;
        }
        if(key < arr[middle]){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
}

int main(){
    
    


    return 0;
}