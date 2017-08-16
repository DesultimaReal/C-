#include <iostream>

using namespace std;

int main()
{
    //int * p;
    //int a = 10;
    //p = &a;
    //cout << *p << endl;

    int * p = new int; //Allocate 4 bytes for p
    *p = 100; //Store 100 into this int pointer
    //cout << *p << endl; //Print the pointer
    delete p; //Free the space

    int N;
    cout << "Enter Elenumber: ";
    cin >> N;
    //Dynamic array
    int * A = new int[N];
    for(int i = 0; i < N; i++)
        cin >> A[i];
    cout << "-------------" << endl;

    for(int i = 0; i < N; i++)
        cout << A[i] << endl;
    delete[] A; //Deallocate A Array

    return 0;
}
