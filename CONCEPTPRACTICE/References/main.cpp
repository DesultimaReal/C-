#include <iostream>

using namespace std;
class Dummy
{
private:
    int value;
public:
    Dummy(){
        value = 0;
    }
    Dummy(int val)
    {
        value = val;
    }
    Dummy operator+(Dummy a)
    {
        cout << "DummyAddition occured!" << endl;
        return Dummy(this->value + a.value);
    }
    Dummy operator-(Dummy a)
    {
        cout << "DummySub occured!" << endl;
        return Dummy(this->value - a.value);
    }
    friend ostream & operator<<(ostream & o, Dummy a)
    {
        o << a.value;
        return o;
    }
    inline int getValue() {return value;}
};
void increase(int * p)
{
    (*p)++;
}
int main()
{
   //Increase and references//
    int a = 10;
    //cout << a << endl;
    increase(&a);
    //cout << a << endl;

    //Dummy Overloading Operators//
    Dummy d(5);
    Dummy b = 10;
    Dummy c = d + b;
    cout << c << endl;

    return 0;
}
