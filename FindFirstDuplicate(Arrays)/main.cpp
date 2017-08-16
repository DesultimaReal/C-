#include <iostream>
#include <vector>
#include <complex>
using namespace std;
//These are some of the various ways I thought of to find the first duplicate in a vector using some creative and less creative methods.

int firstDuplicateInefficient(std::vector<int> a) {
    vector <int> TrackerArray(1000000,0);
    for(int i = 0; i < a.size(); i++){
        int current = a[i];
        //cout << current << "IS CURRENT"<<endl;
        TrackerArray[current]++;
        if( TrackerArray[current]> 1){
            return current;
        }
    }
    return -1;
}
//The more efficient version of above code
int firstDuplicate(std::vector<int> a) {
    for(int i=0;i<a.size();i++){//For each number in our vector
        int v = abs(a[i]) -1;//Get the absolute value of the number - 1 as v
        //cout << "v: " << v << endl;
        //cout << a[v] << " is a[v] " << endl;
        if(a[v] < 0) {
            return v + 1;
        }//if the number in position v is negative return v+1
        a[v] = -a[v];//
    }
    return -1;
}
//Uses Memory to save even more time
int firstDuplicateUsingMemory(std::vector<int> a) {//0x7fff9bd87844 //0x7fff9bd87844
    for(int i:a) {
        i=i&0x7fffffff;
        if(a[i-1]>>31){
            //cout << i <<" " <<&i<<endl; //Checking the address
            return i;
        }
        else
            a[i-1]|=1<<31;

    }
    return -1;
}
int main()
{
    vector<int> a = {1,2,3,4,5,2,6,5};//These will pass larger and more complex/erring tests than just this
    cout << "firstDuplicateUsingMemory: " << firstDuplicateUsingMemory(a) << endl;
    cout << "firstDuplicate: " <<firstDuplicate(a) << endl;
    cout << "firstDuplicateInefficient: " << firstDuplicateInefficient(a) << endl;//This is the simplest yet least efficient way I could do quickly
    return 0;
}
