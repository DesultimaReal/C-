#include <iostream>
#include <algorithm>
using namespace std;
bool palindrome(string racecar){ //Non cheaty n/2 efficiency palindrome
    //Iterate through half, moving that to a new queue and then compare to other half.
    char middleletter;
    int OrigLen = racecar.length();
    bool addmiddle = false;
    if((racecar.length() % 2) == 1){ //Theres a middleletter
        middleletter = racecar[(racecar.length() / 2)];
        addmiddle = true;
        cout << "what";
    }
    string temp = "";
    for(int i = 0; i < OrigLen / 2; i++){ //For the first x letters where x is the first half
        temp.push_back(racecar[racecar.length() - 1]);
        racecar.pop_back();
    }
    if(addmiddle){
        temp.push_back(char(middleletter));
    }
    cout << racecar << " is original string" << endl;
    cout << temp << " is the new string" << endl;
    if(racecar == temp){
        return true;
    }
    return false;
}
bool palincheat(string word)//requires algorithm
{
string w2 = word;
reverse(w2.begin(), w2.end());
return (word == w2);

}
int main()
{
    string dik = "spaccaps";
    cout << palindrome(dik) << " is result palindrome\n";
    cout << palincheat(dik) << " is result palincheat\n";
    return 0;
}
