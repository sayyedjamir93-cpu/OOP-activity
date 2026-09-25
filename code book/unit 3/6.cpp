#include <iostream>
class Distance {
private:
    int meters;
public:
    explicit Distance(int value) : meters(value) {}
    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }
    bool operator==(const Distance& other) const {
        return meters == other.meters;
    }
    void display() const {
        std::cout << meters << " meters\n";
    }
};
int main() {
    Distance first(120);
    Distance second(90);
    Distance third(120);
    if (first > second) {
        std::cout << "First distance is greater than second\n";
    }
    if (first == third) {
        std::cout << "First distance and third distance are equal\n";
    } else {
        std::cout << "First distance and third distance are not equal\n";
    }
    return 0;
}