#include <iostream>
#include <string>
#include <vector>

class Employee {
protected:
    int id;
    std::string name;
    int age;
    double salary;

public:
    Employee(int _id, const std::string& _name, int _age, double _salary)
        : id(_id), name(_name), age(_age), salary(_salary) {}

    virtual void displayInfo() const {
        std::cout << "ID: " << id 
                  << ", Ten: " << name 
                  << ", Tuoi: " << age 
                  << ", Luong: " << salary << std::endl;
    }

    virtual double getSalary() const {
        return salary;
    }

    void increaseSalary(double amount) {
        salary += amount;
    }

    virtual ~Employee() = default; // �?m b?o x�a ��ng ki?u
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(int _id, const std::string& _name, int _age, double _salary, int _teamSize)
        : Employee(_id, _name, _age, _salary), teamSize(_teamSize) {}

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "So nhan vien quan ly: " << teamSize << std::endl;
    }

    double getSalary() const override {
        return salary + (teamSize * 1000); // Phu cap quan ly
    }
};

class Company {
private:
    std::vector<Employee*> employees;

public:
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void displayAllEmployees() const {
        for (const auto& emp : employees) {
            emp->displayInfo();
            std::cout << "------------------------" << std::endl;
        }
    }

    double getTotalSalary() const {
        double total = 0;
        for (const auto& emp : employees) {
            total += emp->getSalary();
        }
        return total;
    }

    ~Company() {
        for (auto emp : employees) {
            delete emp; // Gi?i ph�ng b? nh?
        }
    }
};

int main() {
    Company myCompany;
    myCompany.addEmployee(new Employee(1, "Nguyen Van A", 30, 10000000));
    myCompany.addEmployee(new Employee(2, "Tran Thi B", 25, 8000000));
    myCompany.addEmployee(new Manager(3, "Le Van C", 40, 20000000, 5));

    std::cout << "Thong tin tat ca nhan vien:" << std::endl;
    myCompany.displayAllEmployees();
    std::cout << "Tong luong cong ty: " << myCompany.getTotalSalary() << std::endl;

    return 0;
}

