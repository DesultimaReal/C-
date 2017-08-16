#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("example.txt");
    myfile << "String in File\n";
    myfile.close();
    return 0;
}
D:\Users\StarvinMarvin\Desktop\ofstream\main.cpp
