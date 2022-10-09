#include "EmployeeManager.h"
#include "FilesHelper.h"
#include "ClientManger.h"
FileManager f;
string EmployeeManager::enterName() {
	string name;
	do
	{
		system("cls");
		cout << "the name must be alphabetic chars and min size 5 and max size 20\n";
		cout << "ENTER YOUR NAME PLEASE: \n\n";
		cin >> name;
		Validation(name);
	} while (!Validation::checkName(name));
	return name;
}
string EmployeeManager::enterPAssword() {
	string password;
	do
	{
		system("cls");
		cout << "Password must be with min size 8 and max size 20\n";
		cout << "ENTER YOUR PASSWORD PLEASE: \n\n";
		cin >> password;
		Validation(password);
	} while (!Validation::checkPassword(password));
	return password;
}
double EmployeeManager::enterBalance() {
	double balance;
	do
	{
		system("cls");
		cout << "Min balance is 1500\n";
		cout << "ENTER YOUR BALANCE PLEASE: \n\n";
		cin >> balance;
		Validation(balance);
	} while (!Validation::checkBalance(balance));
	return balance;
}

void EmployeeManager::printEmployeeMenu()
{
	cout << "(1) Display my info" << endl;
	cout << "(2) Update Password" << endl;
	cout << "(3) Add new client" << endl;
	cout << "(4) Search for client" << endl;
	cout << "(5) List all clients" << endl;
	cout << "(6) Edit client info" << endl;
	cout << "(7) Logout\n" << endl;
}
void EmployeeManager::newClient(Employee* employee) {
	system("cls");
	Client client;
	client.setId(FilesHelper::getLast("ClientId.txt"));
	client.setName(enterName());
	client.setPasswword(enterPAssword());
	client.setBalance(enterBalance());
	cout << "CLIENT ADDED\n\n";
	employee->addClient(client);
}

void EmployeeManager::listAllClients(Employee* employee) {
	for (int i = 0; i < f.getAllClients().size(); i++) {
		f.getAllClients()[i].display();
	}
}
void EmployeeManager::searchForClient(Employee* employee) {
	bool flag = false;
	int id;
	system("cls");
	do
	{
		
		cout << "ENTER ID TO SEARCH \n\n";
		cin >> id;
		if (employee->searchClient(id) != nullptr)
		{
			flag = true;
			employee->searchClient(id)->display();
			system("pause");
		}
		else {
			system("cls");
			cout << "NOT FOUND\t\tPLEAS ENTER CORRECT ID\n\n";
		}
	} while (flag == false);
	system("cls");
}
void EmployeeManager::editClientInfo(Employee* employee) {
	vector<Client> v = f.getAllClients();
	Client client;
	int id;
	bool flag = false;
	do
	{
		cout << "ENTER ID: \n\n";
		cin >> id;
		for (int i = 0; i < f.getAllClients().size(); i++) {
			if (id ==v[i].getId()) {
				v[i].setName(enterName());
				v[i].setPasswword(enterPAssword());
				v[i].setBalance(enterBalance());
				employee->editClient(v[i].getId(),v[i].getName(),v[i].getPassword(), v[i].getBalance());
				flag = true;
				break;
			}
		}
		if (flag == false) {
			system("cls");
			cout << "ID NOT FOUND \n\n";
		}
	} while (flag == false);
	cout << "DATA Modified\n\n";
	system("pause");
}

Employee* EmployeeManager::login(int id, string password) {
	vector <Employee> v = f.getAllEmployees();
	Employee* employee = new Employee;
	bool flag = false;
	for (int i = 0; i < v.size(); i++) {
		if (id == v[i].getId() && password == v[i].getPassword()) {
			*employee = v[i];
			employeeOptions(employee);
			flag = true;
			return employee;
		}
	}
	
	return nullptr;
}

string EmployeeManager::passwordSet()
{
	string password;
	do {

		cout << "Enter New Password: ";
		cin >> password;
	} while (!(Validation::checkPassword(password)));
	return password;
}
void EmployeeManager::updatePassword(Employee* p)//me7taga tetrage3
{
	system("cls");
	FileManager f;
	Admin e;
	vector<Employee> v = f.getAllEmployees();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getId() == p->getId())
		{
			v[i].setPasswword(passwordSet());
			p->setPasswword(v[i].getPassword());
			e.editEmployee(v[i].getId(), v[i].getName(), v[i].getPassword(), v[i].getSalary());
			cout << "PASSWORD UPDATED\n\n";
			return;
		}
	}

}


bool EmployeeManager::employeeOptions(Employee* employee) {
	system("color 50");
	system("cls");
	do
	{	
		printEmployeeMenu();
		/*cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Logout\n" << endl;*/
		int option;
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			employee->display();
			system("pause");
			break;
		case 2:
			EmployeeManager::updatePassword(employee);
			system("pause");
			break;
		case 3:
			newClient(employee);
			system("pause");
			break;
		case 4:
			searchForClient(employee);
			break;
		case 5:
			system("cls");
			employee->listClient();
			system("pause");
			system("cls");
			break;
		case 6:
			editClientInfo(employee);
			system("cls");
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			cout << "INCORRECT CHOICE\nPLEASE ENTER THE CORRECT CHOICE\n\n";
			break;
		}
	} while (true);
}