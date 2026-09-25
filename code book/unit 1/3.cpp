#include <iostream>
using namespace std;
int main()
{
    int marks[5] = {78, 82, 91, 67, 88}; // marks array stores five values.
    for (int i = 0; i < 5; i++)          // for loop repeats five times. | i is the index variable.
    {
        cout << marks[i] << " "; // marks[i] accesses each element.
    }
return 0;
}
