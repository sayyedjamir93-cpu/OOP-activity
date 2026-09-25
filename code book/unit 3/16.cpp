#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
class Employee {
protected:
    int employeeId;
    std::string name;
public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}
    virtual double calculateSalary() const = 0;
    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }
    virtual ~Employee() = default;
};
class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;
public:
    PermanentEmployee(int id, std::string employeeName, double basic, double extra)
        : Employee(id, std::move(employeeName)), basicSalary(basic), allowance(extra) {}
    double calculateSalary() const override {
        double gross = basicSalary + allowance;
        double tax = gross * 0.10; 
        return gross - tax;
    }
};
class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    ContractEmployee(int id, std::string employeeName, double rate, int hours)
        : Employee(id, std::move(employeeName)), hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};
class FreelanceEmployee : public Employee {
private:
    int projectsCompleted;
    double payPerProject;
public:
    FreelanceEmployee(int id, std::string employeeName, int projects, double rate)
        : Employee(id, std::move(employeeName)), projectsCompleted(projects), payPerProject(rate) {}
    double calculateSalary() const override {
        return projectsCompleted * payPerProject;
    }
};
int main() {
    std::vector<std::unique_ptr<Employee>> payroll;
    payroll.push_back(std::make_unique<PermanentEmployee>(101, "Asha", 40000.0, 8000.0));
    payroll.push_back(std::make_unique<ContractEmployee>(102, "Vikas", 500.0, 80));
    payroll.push_back(std::make_unique<FreelanceEmployee>(103, "Rahul", 3, 15000.0));
    double totalPayroll = 0.0;
    for (const auto& emp : payroll) {
        emp->displayBasicDetails();
        double salary = emp->calculateSalary();
        std::cout << "Net Salary: Rs. " << salary << "\n\n";
        totalPayroll += salary;
    }

    std::cout << "====================================\n";
    std::cout << "Total Company Payroll: Rs. " << totalPayroll << '\n';
    std::cout << "====================================\n";
    return 0;
}