#include <iostream>
using namespace std;

class Test
{
private:
    int value; // value is private.
public:
    Test(int v)
    { // constructor stores initial value.
        value = v;
    }
    inline int getValue() // inline getter returns value quickly.
    {
        return value;
    }
    friend void show(Test t); // friend function accesses private data.
};
void show(Test t)
{
    cout << t.value;
}
int main()
{
    Test obj(50);
    cout << obj.getValue() << endl;
    show(obj);
    return 0;
}