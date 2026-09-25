#include <iostream>
using namespace std;

int add(int, int); // Prototype informs compiler
int main()         // main starts execution.
{
    int a = 10, b = 20;
    cout << "Sum = " << add(a, b) << endl; // add(a, b) calls function.
    return 0;                              // return gives output.
}
int add(int x, int y)
{ // x and y receive values.
    return x + y;
}