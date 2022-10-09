#include "AdminManager.h"
#include "EmployeeManager.h"
#include "FilesHelper.h"
FileManager f12;
void AdminManager::printAdminMenu() {
	
	cout << "(1) Display my info" << endl;
	cout << "(2) Add new client" << endl;
	cout << "(3) Search for client" << endl;
	cout << "(4) List all clients" << endl;
	cout << "(5) Edit client info" << endl;
	cout << "(6) Add new Employee" << endl;
	cout << "(7) Search for Employee" << endl;
	cout << "(8) List all Employees" << endl;
	cout << "(9) Edit Employee info" << endl;
	cout << "(10) Logout\n" << endl;
}
double AdminManager::enterSalary() {
	double salary;
	system("cls");
	do
	{
		cout << "ENTER YOUR SALARY PLEASE\n\n";
		cout << "Min Salary 5000\n";
		cin >> salary;
	} while (salary < 5000);
	return salary;
}
Employee* AdminManager::newEmployee() {
	Employee* s = new Employee;
	s->setName(EmployeeManager::enterName());
	s->setId(FilesHelper::getLast("EmployeeId.txt"));
	s->setPasswword(EmployeeManager::enterPAssword());
	s->setSalary(AdminManager::enterSalary());
	return s;
}

int AdminManager::searchEmpl(Admin admin) {
	int id;
	do
	{
		cout << "ENTER ID: \n\n";
		cin >> id;
	} while (admin.searchEmployee(id) == nullptr);
	return id;
}

void AdminManager::editEmployee(Admin admin) {
	int id; string name, pass; double salary;
	id = searchEmpl(admin);
	name = EmployeeManager::enterName();
	pass = EmployeeManager::enterPAssword();
	salary = enterSalary();
	admin.editEmployee(id, name, pass, salary);
}

bool AdminManager::AdminOptions(Admin* admin) {
	system("cls");
	system("color 90");
	printAdminMenu();
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
		system("cls");
		admin->display();
		system("pause");
		AdminOptions(admin);
		break;
	case 2:
		system("cls");
		EmployeeManager::newClient(admin);
		system("pause");
		AdminOptions(admin);
		break;
	case 3:
		system("cls");
		EmployeeManager::searchForClient(admin);
		system("pause");
		AdminOptions(admin);
		break;
	case 4:system("cls");
		EmployeeManager::listAllClients(admin); system("pause");
		AdminOptions(admin);
		break;
	case 5:system("cls");
		EmployeeManager::editClientInfo(admin); system("pause");
		AdminOptions(admin);
		break;
	case 6:system("cls");
		admin->addEmployee(*newEmployee()); system("pause");
		AdminOptions(admin);
		break;
	case 7:system("cls");
		admin->searchEmployee(searchEmpl(*admin))->display(); system("pause");
		AdminOptions(admin);
		break;
	case 8:system("cls");
		admin->listEmployee(); system("pause");
		AdminOptions(admin);
		break;
	case 9:system("cls");
		editEmployee(*admin); system("pause");
		AdminOptions(admin);
		break;
	case 10:system("cls");
		return false;
		break;	
	default:
		AdminOptions(admin);
		break;
	}
	return true;
}

Admin* AdminManager::login(int id, string password) {
	vector<Admin> v = f12.getAllAdmins();
	Admin* admin = new Admin;
	for (int i = 0; i < v.size(); i++) {
		if (id == v[i].getId() && password == v[i].getPassword()) {
			*admin = v[i];
			AdminOptions(admin);
			return admin;
		}
	}
	return nullptr;
}