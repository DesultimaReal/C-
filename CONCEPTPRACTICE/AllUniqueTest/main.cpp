#include <iostream>
#include<stdio.h>
using namespace std;
bool isUnique0(string s) {
    // cannot exceed number of unique characters //O(1) space, O(n) algorithm, assumes ascii
    if (s.length() > 256) return false;
    bool checker[256];
    for (int i = 0; i < s.length(); i++) {
        int val = s.at(i);
        if (checker[val] == true)
            return false;
        checker[val] = true;
    }
    return true;
}
bool AllUnique1(string Stringer){//On^2
    for (int i = 0; i < Stringer.length(); i++){
            for(int j = i+1; j<Stringer.length(); j++){
                if(Stringer[i] == Stringer[j]){
                    return false;
                }
            }
    }
    return true;
}
void MyQuickSort(string Stringer){

}
bool AllUnique2(string Stringer){//Merge or quick sort required O(nlogn) algorithm
    //Sort(Stringer);
    for(int i = 1; i < Stringer.length();i++){
        if(Stringer[i] == Stringer[i-1]){
            return false;
        }
    }
    return true;
}



// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    string Str = "Strabab";
    if(AllUnique2(Str)){
        cout << "Unique!";
    }
    else
        cout << "Not Unique!";


    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
