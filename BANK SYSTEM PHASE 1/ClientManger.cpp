#include "ClientManger.h"
#include "FileManager.h"
#include "Screen.h"
#include "Client.h"
#include<fstream>
void ClientManger::printClientMenu() {
	system("cls");
	system("color 81");
	cout << "\n\n\n1. DISPLAY INFORMATION \n\n2. CHECK BALANCE \n\n3. UPDATE MY PASSWORD \n\n4. DEPOSIT AMOUNT \n\n5. WITHDRARW AMOUNT \n\n"
		<< "6. TRANSFER TO ANOTHER ACCOUNT \n\n7. LOG OUT\n\n\n";
	
}
string passwordSet()
{
	string password;
	do {
		
		cout << "Enter New Password: ";
		cin >> password;
	} while (!(Validation::checkPassword(password)));
	return password;
}
void ClientManger::updatePassword(Person* p)//me7taga tetrage3
{
	FileManager f;
	Employee e;
	vector<Client> v =f.getAllClients();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getId() == p->getId())
		{
			v[i].setPasswword(passwordSet());
			p->setPasswword(v[i].getPassword());
			e.editClient(v[i].getId(), v[i].getName(), v[i].getPassword(), v[i].getBalance());
			return;
		}	
	}

}
Client* ClientManger::login(int id, string password)
{
	FileManager f;
	vector<Client> v = f.getAllClients();
	Client* cl1 = new Client;
	bool flag = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getId() ==id && v[i].getPassword()==password)
		{
			*cl1 = v[i];
			clientOptions(cl1);
			return cl1;
		}
		else {
			flag = true;
		}
	}
	if (flag == true)
	{
		return nullptr;
	}
}

bool ClientManger::clientOptions(Client* ccc)
{
	Client* client = new Client;
	printClientMenu();
	int option, id;
	double amount;
	cin >> option;
	Employee el;
	system("cls");
	switch (option)
	{/*
		cout << "\n\n\n1. DISPLAY INFORMATION \n\n2. CHECK BALANCE \n\n3. UPDATE MY PASSWORD \n\n4. DEPOSIT AMOUNT \n\n5. WITHDRARW AMOUNT \n\n"
			<< "6. TRANSFER TO ANOTHER ACCOUNT \n\n7. LOG OUT\n\n\n";*/

	case 1:
		ccc->display();
		break;
	case 2:
		ccc->checkBalance();
		break;
	case 3:
		updatePassword(ccc);
		break;
	case 4:
		cout << "ENTER AMOUNT TO DEPOSIT\n\n";
		cin >> amount;
		ccc->deposit(amount);
		cout <<"DEPOSITTING SUCCESS\n";
		el.editClient(ccc->getId(), ccc->getName(), ccc->getPassword(), ccc->getBalance());
		break;
	case 5:
		cout << "ENTER AMOUNT TO WITHDRAW\n\n";
		cin >> amount;
		ccc->withdraw(amount);
		el.editClient(ccc->getId(), ccc->getName(), ccc->getPassword(), ccc->getBalance());
		break;
	case 6:
		cout << "ENTER ID \n\n";
		cin >> id;
		client = el.searchClient(id);
		cout << "ENTER AMOUNT TO TRANSFER\n\n";
		cin >> amount;
		ccc->transfer(*client, amount);
		el.editClient(ccc->getId(), ccc->getName(), ccc->getPassword(), ccc->getBalance());
		el.editClient(client->getId(), client->getName(), client->getPassword(), client->getBalance());
		break;
	case 7:
		Screen::loginOptions();
		break;
	default:
		//cout << "INVALID CHOISE\n\nPLEASE TRY AGAIN\n\n";
		printClientMenu();
		break;
	}
	return true;
}