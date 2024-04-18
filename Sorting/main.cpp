#include "Sort.h"
#include <iostream>
using namespace std;

int main(){
  int* arr = new int[6];
  arr[0] = 20;
  arr[1] = 15;
  arr[2] = 2;
  arr[3] = 60;
  arr[4] = 5;
  arr[5] = 10;

  //bubbleSort(arr,6);
  //selectionSort(arr,6);
  //insertionSort(arr,6);
  //mergeSort(arr,0,5);
  quickSort(arr,0,5);


  for(int i = 0; i < 6; ++i){
    cout << arr[i] << endl;
  }

  return 0;
}
