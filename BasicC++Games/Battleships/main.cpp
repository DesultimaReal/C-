#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int rows = 10;
const int elements = 10;
int maxships = 10;

int matrix[rows][elements];

void Clear(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < elements; j++){
            matrix[i][j] = 0;
        }
    }
}
void Show(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < elements; j++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl;
    }
}
void SetShips()
{
    int s = 0;
    while(s < maxships)
    {
            int x = rand() % rows;
            int y = rand() % elements;
            if(matrix[x][y] != 1){
                s++;
                matrix[x][y] = 1;
            }
    }
}
int NumberOfShips()
{
    int c = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < elements; j++){
            if(matrix[i][j] == 1)
                c++;
        }
    }
    return c;
}
bool Attack(int x, int y)
{
    if(matrix[x][y] == 1){
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));
    Clear();
    SetShips();
    Show();
    char prompt;
    int pos1, pos2;
    while(1){
        cout << "Please input location to attack: "; cin >> pos1 >> pos2;
        if(Attack(pos1,pos2))
            cout << "You got me\n";
        else
            cout << "No ship there!\n";
        cout << "NUM SHIPS LEFT: " << NumberOfShips() << endl;
        cout << "SURRENDER? y/n"; cin >> prompt;
        if(prompt == 'y'){
            break;
        }
    }
    cout << "Game over";
    //Show();
    return 0;
}
