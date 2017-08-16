#include <iostream>
using namespace std;
/*

1
2
3
4
5
6
7
8
9


|1 2 3|
|4 5 6|
|7 8 9|
*/
void InputMatrix(int RealMatrix[][3]){

    int row, col = 0;
    for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                cin >> RealMatrix[row][col];
            }
    }
}
void printm(int matrix[][3]){
    for(int x=0;x<3;x++)  // loop 3 times for three lines
    {
        for(int y=0;y<3;y++)  // loop for the three elements on the line
        {
            cout<<matrix[x][y]<<" ";  // display the current element out of the array
        }
    cout<<endl;  // when the inner loop is done, go to a new line
    }
}
int main()
{
    int RealMatrix[3][3];
    InputMatrix(RealMatrix);
    printm(RealMatrix);
}
