#pragma once
#include "Admin.h"
#include "FileManager.h"
class AdminManager
{
public:

	static void printAdminMenu();
	static Admin* login(int id, string password);
	static bool AdminOptions(Admin* admin);
	static Employee* newEmployee();
	static double enterSalary();
	static int searchEmpl(Admin);
	static void editEmployee(Admin);
};

