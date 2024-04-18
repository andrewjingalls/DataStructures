#include <iostream>
using namespace std;

//sort ints
void bubbleSort(int* arr, int n){
  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j < n-i-1; ++j){
      if(arr[j] > arr[j+1]){ //number of comps
        int temp = arr[j];
        arr[j] = arr[j+1]; //number of swaps
        arr[j+1] = temp;
      }
    }
  }
}

//selection sort - pick min each time and put in position at front of the array
void selectionSort(int* arr, int n){
  int currMinIdx;
  for(int j = 0; j < n-1; ++j){
    currMinIdx = j;
    for(int k = j+1; k < n; ++k){
      if(arr[k]< arr[currMinIdx]){ //swap
        currMinIdx = k;
      }
    }
    double temp = arr[j];
    arr[j] = arr[currMinIdx];
    arr[currMinIdx] = temp;
  }
}

void insertionSort(int* arr, int n){
  for(int j = 1; j < n; ++j){
    double temp = arr[j];
    int k = j;
    while(k >0 && arr[k-1] >= temp){
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp;
  }
}

// This function merges two sorted halves of the array into a single sorted array.
void merge(int* arr, int lo, int hi) {
  // Create a temporary array to store the merged result.
  int* newArr = new int[hi - lo + 1];

  // Calculate the middle index of the array.
  int middle = (hi + lo) / 2;

  // Initialize variables for iteration and index tracking.
  int k = 0;
  int i;
  int j;

  // Copy the elements from the left half of the array to the temporary array.
  for (i = lo; i <= middle; ++i) {
    newArr[k++] = arr[i];
  }

  // Copy the elements from the right half of the array to the temporary array in reverse order.
  for (j = hi; j >= middle + 1; --j){
    newArr[k++] = arr[j];
  }

  // Reset variables for the next step.
  i = 0;
  k = lo;
  j = hi - lo; // Number of elements - 1

  // Merge the two halves back into the original array in sorted order.
  while (i <= j) {
    if (newArr[i] < newArr[j]) {
      arr[k++] = newArr[i++];
    } else {
      arr[k++] = newArr[j--];
    }
  }

  // Deallocate the memory used for the temporary array.
  delete[] newArr;
}

// This function recursively sorts the given array using the merge sort algorithm.
void mergeSort(int* arr, int lo, int hi) {
  // Base case: If there is more than one element in the array.
  if (lo < hi) {
    // Calculate the middle index of the array.
    int middle = (lo + hi) / 2;

    // Recursively sort the left and right halves of the array.
    mergeSort(arr, lo, middle);
    mergeSort(arr, middle + 1, hi);

    // Merge the sorted halves.
    merge(arr, lo, hi);
  }
}

// This function selects a pivot element from the array and places it in its correct position.
// It also rearranges the elements in such a way that elements smaller than the pivot are on the left,
// and elements greater than the pivot are on the right.
int partition(int* arr, int lo, int hi) {
  // Choose the rightmost element as the pivot (this can be risky for already sorted data).
  int pivot = arr[hi];
  
  // Initialize an index to keep track of the position of smaller elements.
  int smallValue = lo - 1;

  // Iterate through the array to partition elements around the pivot.
  for (int j = lo; j <= hi - 1; ++j) {
    // If the current element is smaller than the pivot, swap it with the element at the smallValue index.
    if (arr[j] < pivot) {
      ++smallValue;
      
      // Swap arr[j] and arr[smallValue].
      int temp = arr[j];
      arr[j] = arr[smallValue];
      arr[smallValue] = temp;
    }
  }

  // Place the pivot in its correct position.
  int pivotPosition = arr[smallValue + 1];
  arr[smallValue + 1] = arr[hi];
  arr[hi] = pivotPosition;

  // Return the index of the pivot in its final position.
  return (smallValue + 1);
}

// This function recursively sorts the array using the quicksort algorithm.
void quickSort(int* arr, int lo, int hi) {
  // Base case: If there is more than one element in the array.
  if (lo < hi) {
    // Find the partition index.
    int partitionIdx = partition(arr, lo, hi);

    // Recursively sort the left and right subarrays.
    quickSort(arr, lo, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, hi);
  }
}


void median3(int* arr, int lo, int hi){
  int center = (lo+hi)/2;
  //compare arr[lo], arr[center], arr[hi] and find the middle value (median)
  //swap arr[hi] with the median
}

