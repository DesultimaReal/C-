#include <iostream>

using namespace std;

int main()
{
    string *stringArray = new string[100];
    //stringArray[0] = "First";
    stringArray[0] = "NextToLast";
    stringArray[1] = "Hello";
    stringArray[2] = "Greetings";//stringArray[100] = "Last";
    //delete [] stringArray; // Kill the array, free memory
    delete stringArray; // Kill the string at position 0 lol
    //cout << stringArray[0];
    cout << stringArray[1];
    //cout << stringArray[100];

    return 0;
}
