#include <iostream>
class Base {
public:
    void display() const {
        std::cout << "Base display function\n";
    }
};
class Derived : public Base {
public:
    void display() const {
        std::cout << "Derived display function\n";
    }
};
int main() {
    Derived derivedObject;
    Base* basePointer = &derivedObject;
    std::cout << "Call via Base pointer: ";
    basePointer->display(); 
    std::cout << "Direct call on Derived object: ";
    derivedObject.display(); 

    return 0;
}