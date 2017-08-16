#include <iostream>
#include <vector>
#include <random>
using namespace std;
#define MAXBUNNYNUMBERS 5
enum type{
    brown = 0,
    white = 1
};
class Bunny{
private:
    int color;
    string name;
public:
    Bunny(string Pname){
        color = rand() % 2;
        name = Pname;
    }
    string GetName(){
        return name;
    }
};
class BunnyCage{
private:
    //vector<Bunny> BunnyStorage;
    Bunny *BunnyArray[MAXBUNNYNUMBERS];

    int CurrentBunny;
    int Y;
public:
    BunnyCage(int X){
        Y = X;
        CurrentBunny = 0;
    }
    ~BunnyCage(){

    }
    void AddBunny(string Joe){
        BunnyArray[CurrentBunny] = new Bunny(Joe);
        CurrentBunny++;
    }
    void PrintCage(){
        for(int i = 0; i < CurrentBunny; i++){
            cout << BunnyArray[i]->GetName() << endl;
        }
    }
    void Run(){

        cout << "Starting\n";
        string x;
        while(cin >> x){
            if(x == "new"){
                //Create a new rabbit
                cout << "EnterName: ";
                string name;
                cin >> name;
                AddBunny(name);
            }
            if(x == "del"){
                //Delete a rabbit
            }
            if(x == "pri"){
                //Print our created rabbits
                PrintCage();
            }
            //Accept new Bunnys
            //Find and Delete a Bunny efficiently
        }
    }

};
int main()
{
    BunnyCage Bun1(5);
    Bun1.Run();
}
