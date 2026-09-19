 // A company employs full time employees, part time employees, and interns.
// All employees share common information, but salary calculations vary by employment type.

#include <iostream>
#include <string>
using namespace std;

class employee {
    protected:
    int empld;
    string name;
    string department;
    public:
    employee(int id, string n, string dept)
    : empld(id), name(n), department(dept) {}
    void displaybasicinfo() const {
        cout << "ID:" << empld
             << "|Name:" << name << "|Department:" << department;
    }
    virtual double calculatesalary() const = 0;
    virtual ~employee() = default;
};

class fulltimeemployee : public employee {
    private:
    double monthlysalary;
    public:
    fulltimeemployee(int id, string n, string dept, double salary)
    : employee(id, n, dept), monthlysalary(salary) {}
    double calculatesalary() const override {
        return monthlysalary;
    }
    void display() const {
        displaybasicinfo();
        cout << "|Type: Full Time| Salary: Rs." << calculatesalary() << endl;
    }
};

class parttimeemployee : public employee {
    private:
    double hourlyrate;
    int hoursworked;
    public:
    parttimeemployee(int id, string n, string dept, double rate, int hours)
    : employee(id, n, dept), hourlyrate(rate), hoursworked(hours) {}
    double calculatesalary() const override {
        return hourlyrate * hoursworked;
    }
    void display() const {
        displaybasicinfo();
        cout << "|Type: Part Time| Salary: Rs." << calculatesalary() << endl;
    }
};

class intern : public employee {
    private:
    double stipend;
    public:
    intern(int id, string n, string dept, double stipendAmount)
    : employee(id, n, dept), stipend(stipendAmount) {}
    double calculatesalary() const override {
        return stipend;
    }
    void display() const {
        displaybasicinfo();
        cout << "|Type: Intern| Stipend: Rs." << calculatesalary() << endl;
    }
};

int main() {
    fulltimeemployee ft(101, "Aman", "IT", 65000);
    parttimeemployee p1(102, "Puja", "HR", 250, 120);
    intern i1(103, "Vikram", "Marketing", 15000);

    cout << "------ Employee Payroll ------" << endl;
    ft.display();
    p1.display();
    i1.display();

    return 0;
}
