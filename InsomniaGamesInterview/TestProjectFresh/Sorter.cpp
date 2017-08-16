// An all sorter that can sort arrays in various ways
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
void PrintArraySimple(int test[],int length){

    cout << test[0];
    for (int i = 1; i < length; i++){
        cout <<','<< test[i];
    }
}
int GetArrayLength(int test[]){

    int sizeoftest = sizeof(test);
    int sizeofelement = sizeof(test[0]);
    cout << "ArraySize: " << sizeoftest << endl; //20 = int size 4 * 5;
    cout << "ElementSize: " << sizeofelement << endl;
    int Length = sizeoftest/sizeofelement;
    cout << "ArrayLength: " <<Length << endl;
    return Length;
}
void InsertionSort(int test[], int length){
    int position, temp;
    for (int i = 0; i < length; i ++){
        position = i;
        while(position > 0 && test[position] < test[position-1]){
            std::swap(test[position], test[position-1]);
            position--;
        }
    }
}

void BubbleSort(int test[], int length){

    for(int i = 1; i < length; ++i){
        for(int j = 0; j<(length-i); ++j){
                if(test[j] > test[j+1])
                {
                    std::swap(test[j], test[j+1]);
                }
        }
    }
}
int PointerConcept(){



// Static allocation
int number = 88;
int * p1 = &number;  // Assign a "valid" address into pointer

// Dynamic Allocation
int * p2;            // Not initialize, points to somewhere which is invalid
cout << p2 << endl; // Print address before allocation
p2 = new int;       // Dynamically allocate an int and assign its address to pointer
                    // The pointer gets a valid address with memory allocated
*p2 = 99;
cout << p2 << endl;  // Print address after allocation
cout << *p2 << endl; // Print value point-to
//cout << typename(p2) << endl;
cout << sizeof(p2) << endl;
delete p2;           // Remove the dynamically allocated storage
}
int main()
{

    int test[] = {5,4,2,1,3};
    int length = sizeof(test)/sizeof(test[0]);
    //InsertionSort(test, length);
    //BubbleSort(test,length);
    PrintArraySimple(test, length);
    //for (int i = 1; i < test.length; i++){
    //    cout << test[i];
    //}


}


