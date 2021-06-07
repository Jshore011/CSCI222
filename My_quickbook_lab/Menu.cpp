#include "Menu.h"
#include "Employee.h"
#include "Driver.h"

using namespace std;

void Menu::displayMenu(void)
{
	//displays menu
	cout << "1 - Add Employee" << endl;
	cout << "2 - Display Employee" << endl;
	cout << "3 - Modify Employee" << endl;
	cout << "4 - Delete Employee" << endl;
	cout << "5 - List of Employees" << endl;
	cout << "6 - Employee Salary Slip" << endl;
	cout << "7 - Exit" << endl;
	


}

int Menu::getSelection()
{
	//get's user selection
	cin >> selection;
	return selection;
}
