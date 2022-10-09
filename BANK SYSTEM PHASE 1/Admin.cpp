#include "Admin.h"
#include "FileManager.h"
#include <fstream>
FileManager ff;
ofstream o2;
Admin::Admin() {}
Admin::Admin(string name, int id, string password, double salary) :Employee(name,id,password,salary) {}

void Admin::display() {
    cout << "ADMIN DATA: "
        << "NAME: " << name << endl
        << "ID: " << id << endl
        << "PASSWORD:" << password << endl
        << "SALARY: " << salary << endl
        << "===========================================\n";
}
void Admin::addEmployee(Employee& e) {
    ff.addEmployee(e);
}

Employee* Admin::searchEmployee(int id) {
    Employee* emp = new Employee;
    for (int i = 0; i < ff.getAllEmployees().size() - 1; i++) {
        if (id == ff.getAllEmployees()[i].getId()) {
           *emp = ff.getAllEmployees()[i];
            return emp;
        }
    }
    return nullptr;
}

void Admin::listEmployee() {
    for (int i = 0; i < ff.getAllEmployees().size(); i++) {
        ff.getAllEmployees()[i].display();
    }
}

void Admin::editEmployee(int id, string name, string password, double salary) {
    vector<Employee> temp = ff.getAllEmployees();
    for (int i = 0; i < temp.size() - 1; i++) {
        if (id == temp[i].getId()) {
            temp[i].setInfo(name, id, password, salary);
            break;
        }
    }
    o2.open("Temp.txt", ios::app);
    for (int i = 0; i < temp.size() - 1; i++) {
        o2 << temp[i].getName() << " "
            << temp[i].getId() << " "
            << temp[i].getPassword() << " "
            << temp[i].getSalary() << endl;
    }
    o2.close();
    remove("Employee.txt");
    rename("Temp.txt", "Employee.txt");
    return;
}
