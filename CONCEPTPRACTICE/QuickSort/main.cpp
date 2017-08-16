#include <iostream>
using namespace std;
/*
Choose a pivot value. We take the value of the middle element as pivot value, but it can be any value, which is in range of sorted values, even if it doesn't present in the array.
Partition. Rearrange elements in such a way, that all elements which are lesser than the pivot go to the left part of the array and all elements greater than the pivot, go to the right part of the array. Values equal to the pivot can stay in any part of the array. Notice, that array may be divided in non-equal parts.
Sort both parts. Apply quicksort algorithm recursively to the left and the right parts.*/

void QuickSort(char chararray[] , int left, int right){
    int pivotpos = ((left + right) / 2);
    char pivot = chararray[pivotpos]; //This is working right
    char temp;
    //cout << pivot << endl;
    int leftmover = left, rightmover = right;
        //  0           ArrayLength-----Partition
    while (leftmover <= rightmover){ //While our leftspot is less than our rightspot
        while(chararray[leftmover] < pivot){
            //While our character in our leftspot is less than pivot
            //Increment our leftspot to the right, as the
            //thing there in it's position already
            leftmover++;
        }
        while(chararray[rightmover] > pivot){
            //The same for our rightspot
            rightmover--;
        }
        if(leftmover <= rightmover){
            //swap
            temp = chararray[leftmover];
            chararray[leftmover] = chararray[rightmover];
            chararray[rightmover] = temp;
            leftmover++;
            rightmover--;
        }
    };
     //recursion
      if (left < rightmover)
            QuickSort(chararray, left, rightmover);
      if (leftmover < right)
           QuickSort(chararray, leftmover, right);
}

printArray(char chararray[], int ArrayLength){
    cout << ArrayLength << " <-ArrayLength\n";
        for (int i = 0; i < ArrayLength; i++){
            cout << chararray[i] << " ";
        }
        cout << endl;
}

int main()
{ // d > c > b... ect//
    char chararray[] = {'a','b','e','c','f','g','a'};//Array exsists as 7 1 byte chars
    int ArraySize = sizeof(chararray), CharacterSize = sizeof(chararray[0]), ArrayLength = ArraySize / CharacterSize;
    printArray(chararray, ArrayLength); //The pointer to the arrray is passed to printArray
    int arraytop = (sizeof(chararray)/sizeof(chararray[0]))-1;
    QuickSort(chararray, 0, arraytop);
    printArray(chararray, ArrayLength);
    return 0;
}
