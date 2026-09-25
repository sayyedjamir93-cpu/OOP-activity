#include <iostream>
using namespace std;

class Student
{
public:
    static int count; // static count belongs to class
    Student()
    {
        count++; // constructor increases count.
    }
};

int Student::count = 0; // Student::count defines shared data.

int main()
{
    Student s1, s2, s3;
    cout << Student::count; // class name accesses static member.
    return 0;
}