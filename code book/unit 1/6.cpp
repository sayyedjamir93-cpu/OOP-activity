#include <iostream>
using namespace std;
class Demo
{
public:
    Demo() // Demo() is constructor. | It runs when object is created.
    {
        cout << "Constructor called\n"; // Messages show execution order.
    }
    ~Demo() // Demo() is destructor. | It runs when object ends.
    {
        cout << "Destructor called\n";
    }
};

int main()
{
    Demo d;
    return 0;
}