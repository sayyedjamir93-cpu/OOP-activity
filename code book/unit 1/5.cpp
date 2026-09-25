#include <iostream>
using namespace std;

class Student // class defines blueprint.
{
public:
    string name; // string and int are data members.
    int age;
    void show()
    { // show() is a member function.
        cout << name << " " << age << endl;
    }
};

int main()
{
    Student s1;       // s1 is an object.
    s1.name = "Amit"; // Values are assigned using dot operator.
    s1.age = 20;
    s1.show();
    return 0;
}