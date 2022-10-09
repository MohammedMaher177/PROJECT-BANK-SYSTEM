#include <iostream>
#include <vector>
#include <string>
#include "Client.h"
#include "Admin.h"
#include "DataSource.h"
#include "FileManager.h"
#include "Parser.h"
#include "ClientManger.h"
#include "Screen.h"
#include "FilesHelper.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

using namespace std;

int main()
{
	/*Client* c = new Client("sadasd", 777, "asdasdda", 152255);
	ClientManger::clientOptions(c);*/
	//ClientManger::updatePassword(p);
	//cout << p->getPassword();
	/*do {
		cout << "ENTER ID AND PASSWORD\n";
		cin >> id;
		cin >> password;
	}
	while (ClientManger::login(id, password) == nullptr);
	Client* s =ClientManger::login(id, password);
	s->display();
	*/
	/*Screen::bankName();
	Screen::welcome();
	Screen::loginOptions();
	Screen::loginAs();*/
	//Employee e;
	/*Client c("AHMED", FilesHelper::getLast("ClientId.txt"), "12345678", 25000);
	e.addClient(c);
	cout <<FilesHelper::getLast("ClientId.txt");*/

	//Employee* employ = new Employee;
	////employ->setInfo("MOHAMMED", 555, "MOHAMMED123", 20000);
	//Admin a("MAHMOUD", 555, "MAHMOUD", 10000);
	//Employee e;
	//Client c("MAHMOUD", FilesHelper::getLast("ClientId.txt"), "44444444", 250000);
	//e.addClient(c);
	/*if (EmployeeManager::login(555, "AHMED123") == nullptr) cout << "NOT FOUND\n\n";
	else 
	{
		EmployeeManager::login(555, "AHMED123")->display();
	}*/
	//EmployeeManager::employeeOptions(employ);
	//e.listClient();
	//Screen::loginOptions();
	//AdminManager::AdminOptions(&a);

	Screen::runApp();
}
