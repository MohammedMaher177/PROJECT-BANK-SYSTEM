#include "Screen.h"
#include "ClientManger.h"
#include <Windows.h>
#include "EmployeeManager.h"
#include "AdminManager.h"
void Screen::bankName() {
	system("cls");
	system("color 81");
	WCHAR text[1024];

	cout << "\n\n\n\n\n"
		<< "\t\t\t\t\t***********    ********   ************\n";
	Sleep(1000);
	cout << "\t\t\t\t\t*                 **      *           \n";
		Sleep(1000);
		cout << "\t\t\t\t\t*                 **      *           \n";
		Sleep(1000);
		cout<< "\t\t\t\t\t***********       **      ************\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t           *      **                 *\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t           *      **                 *\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t           *      **                 *\n";
		Sleep(1000);
		cout<< "\t\t\t\t\t***********    ********   ************\n\n";
	Sleep(2000);
	cout << "\t\t\t\t\t********       **      ****       **  **   **\n"
		<< "\t\t\t\t\t*       *     ** **    ** **      **  **  **\n"
		<< "\t\t\t\t\t*        *   **   **   **  **     **  ** **\n"
		<< "\t\t\t\t\t*********   **     **  **   **    **  ****\n"
		<< "\t\t\t\t\t*        *  *********  **    **   **  ** **\n"
		<< "\t\t\t\t\t*         * **     **  **     **  **  **  **\n"
		<< "\t\t\t\t\t*         * **     **  **      ** **  **   **\n"
		<< "\t\t\t\t\t**********  **     **  **       ****  **    **\n\n";
	Sleep(2000);
}
void Screen::welcome() {
	system("cls");
	system("color 9f");
	cout << "\n\n\n\n\n\n\n\n";
	cout << "**            ****            **  **************  **            **************  ************** ****            ****\n"
		<< " **          **  **          **   **              **            **              *            * ** **          ** **\n"
		<< "  **        **    **        **    **              **            **              *            * **  **        **  **\n"
		<< "   **      **      **      **     ************    **            **              *            * **   **      **   **\n"
		<< "    **    **        **    **	  **              **            **              *            * **    **    **    **\n"
		<< "     **  **          **  **       **              **            **              *            * **     **  **     **\n"
		<< "      ****            ****        *************** ************* **************  ************** **      ****      **\n";
	Sleep(2000);
}
void Screen::loginOptions()
{	
	system("cls");
	system("color 81");
	cout << "LOG IN AS: \n\n";
	cout << "1. ADMIN\n\n"
		<< "2. EMPLOYEE\n\n"
		<< "3. CLIENT\n\n";
	loginAs();
}
int Screen::loginAs()
{
	int option;
	cout << "--> ";
	cin >> option;
	loginScreen(option);
	return option;
}
void Screen::loginScreen(int c)
{
	int id; string password;
	system("cls");
	cout << "ENTER YOUR ID PLEASE\n\n";
	cin >> id;
	cout << "EENTER YOUR PASSWORD PLEASE\n\n";
	cin >> password;
	switch (c)
	{
	case 1:
		if (AdminManager::login(id, password) == nullptr) loginOptions();
		AdminManager::login(id, password);
		break;
	case 2:
		if (EmployeeManager::login(id, password) == nullptr) loginOptions();
		EmployeeManager::login(id, password);
		break;
	case 3:
		
		ClientManger::login(id,password);
		break;
	default:
		invalid(c);
		break;
	}
}
void Screen::invalid(int c)
{
	loginOptions();
}

void Screen::runApp() {
	bankName();
	welcome();
	loginOptions();
}