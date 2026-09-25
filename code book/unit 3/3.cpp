#include <iostream>
class Balance {
private:
    double amount;
public:
    explicit Balance(double value) : amount(value) {}
    Balance operator-() const {
        return Balance(-amount);
    }
    void display() const {
        std::cout << "Rs. " << amount << '\n';
    }
};
int main() {
    Balance currentBalance(5000.50);
    Balance negativeBalance = -currentBalance;
    std::cout << "Original Balance: ";
    currentBalance.display();
    std::cout << "Negated Balance: ";
    negativeBalance.display();
    return 0;
}