// Unit II mini project

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
  int accountNumber;
  string holderName;
  double balance;

public:
  Account(int accNo, string name, double bal) {
    accountNumber = accNo;
    holderName = name;
    balance = bal;
  }
  virtual void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      cout << "Deposited: Rs. " << amount << endl;
    } else {
      cout << "Invalid deposit amount!" << endl;
    }
  }
  virtual void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      cout << "Withdrawn: Rs. " << amount << endl;
    } else {
      cout << "Insufficient balance!" << endl;
    }
  }
  virtual void calculateInterest() {}
  virtual void display() {
    cout << "Acc No: " << accountNumber << " | Holder: " << holderName
         << " | Balance: Rs. " << balance << endl;
  }
  virtual ~Account() {}
};
class SavingsAccount : public Account {
private:
  double interestRate;

public:
  SavingsAccount(int accNo, string name, double bal, double rate)
      : Account(accNo, name, bal) {
    interestRate = rate;
  }
  void calculateInterest() {
    double interest = (balance * interestRate) / 100;
    balance += interest;
    cout << "Interest added: Rs. " << interest << endl;
  }
  void display() {
    cout << "[Savings Account]" << endl;
    Account::display();
  }
};
class CurrentAccount : public Account {
private:
  double overdraftLimit;

public:
  CurrentAccount(int accNo, string name, double bal, double limit)
      : Account(accNo, name, bal) {
    overdraftLimit = limit;
  }
  void withdraw(double amount) {
    if (amount > 0 && amount <= (balance + overdraftLimit)) {
      balance -= amount;
      cout << "Withdrawn: Rs. " << amount << endl;
    } else {
      cout << "Overdraft limit exceeded!" << endl;
    }
  }
  void calculateInterest() {
    cout << "No interest for Current Account." << endl;
  }
  void display() {
    cout << "[Current Account]" << endl;
    Account::display();
  }
};
class FixedDepositAccount : public Account {
private:
  int tenureMonths;
  double interestRate;

public:
  FixedDepositAccount(int accNo, string name, double bal, int months,
                      double rate)
      : Account(accNo, name, bal) {
    tenureMonths = months;
    interestRate = rate;
  }
  void calculateInterest() {
    double interest = (balance * interestRate * tenureMonths) / (12 * 100);
    cout << "FD Interest for " << tenureMonths << " months: Rs. " << interest
         << endl;
  }
  void display() {
    cout << "[Fixed Deposit Account]" << endl;
    Account::display();
  }
};
int main() {
  Account *acc1 = new SavingsAccount(101, "Ayush chavhan", 10000.0, 4.0);
  Account *acc2 = new CurrentAccount(102, "sakshi gupta", 50000.0, 15000.0);
  Account *acc3 = new FixedDepositAccount(103, "Parth tupe", 100000.0, 12, 7.5);

  cout << "=== BANKING SYSTEM DEMO ===" << endl << endl;

  acc1->display();
  acc1->deposit(2000);
  acc1->calculateInterest();
  acc1->display();
  cout << "-----------------------------------------" << endl;

  acc2->display();
  acc2->withdraw(55000);
  acc2->display();
  cout << "-----------------------------------------" << endl;

  acc3->display();
  acc3->calculateInterest();
  cout << "-----------------------------------------" << endl;

  delete acc1;
  delete acc2;
  delete acc3;
  return 0;
}