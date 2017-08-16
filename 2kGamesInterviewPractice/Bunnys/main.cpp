#include <iostream>
#include <random>
#include <sstream>
#include <time.h>
using namespace std;
const int MAXBUNNIES = 4;


enum eColors{
    Red = 0,
    Blue = 1,
    Yellow = 2
};

class Bunny{
private:
    int Color;
    string Name;
public:
    Bunny(){
        Color = rand() % 3;
        cout << Color << " Is Color\n";
        Name = "OriginalName";
    }
    ~Bunny(){

    }
    //inline int GetColor(){
    //    return Color;
    //}


};

class BunnyCage{
private:
    int MaxRabbitsYo;
    Bunny *ptrArray[MAXBUNNIES];
    //string Colors;
public:
    BunnyCage(int MaxBuns){
        MaxRabbitsYo = MaxBuns;
        cout << "CREATED A CAGE FOR BUNNIES";
        for(int i = 0; i < MaxRabbitsYo; i++){
            cout << "\nFilled " << i << " BunnySpot\n";
            ptrArray[i] = new Bunny();
        }
    }
    ~BunnyCage(){
        for(int i = 0; i < MaxRabbitsYo; i++){
            cout << "\nDeleting " << i << " BunnySpot\n";
            delete ptrArray[i];
        }
    }
    void Run(){
        cout << "\nRUNNING GAME\n";
    }
};

int main()
{
//Create a game with Bunnys assuming that many are being removed and added at the same time
//You have Max_Bunnies
//AddBunny
//removeBunny
//Iterate through Bunnys
//Static Memory/No New????
    srand(time(NULL));
    BunnyCage BunnyGame(MAXBUNNIES);
    BunnyGame.Run();
    //return 0;
}
