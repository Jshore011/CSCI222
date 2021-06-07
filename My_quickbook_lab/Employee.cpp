#include "Employee.h"

using namespace std;

Employee::Employee() //employee constructor
{
	empCode = 0;
	joinDate = Date(0, 0, 0);
	strcpy(name, " "); 
	strcpy(address, " ");
	strcpy(phone, " ");
	strcpy(designation, " ");
	grade = '\0', house = '\0', conv = '\0';
	loan = 0, salary = 0, houseAllowance = 0;
}

Employee::~Employee() // destructor
{
	delete empCode;

}

void Employee::modification(void)
{
//modify's existing employee's record using modify_record function
	cout << "Enter Employee code: "<< endl;
	cin >> empCode;
	
}

//void Employee::delete(void)
//

void Employee::display(void)
{
	//nicely displays employee record

}

void Employee::list(void)
{
	//prints a list of all employees
	
}

void Employee::salary_slip(void)
{
	//asks for employee code
	cout << "Please Enter Employee Code" << endl;
	cin >> empCode;
	//lists all months of the year

	//asks for name, designation, and grade

	//user provides number of days worked in a month
	//no. of hours worked over time
	//cout<<salary<<allowance<<deductions<<netSalary


}

void Employee::add_record(int, char[], char[], char[], int, int, int, char[], char, char, char, float, float)
{ //user is prompted and adds employee information

	cout << "Enter employee name: " << endl;
	cin >> name;
	cout << "Address: " << endl;
	cin >> address;
	cout << "Phone number: " << endl;
	cin >> phone;
	cout << "Join date: " << endl;
	//cin >> Date.day;
	cout << "Designation: " << endl;
	cin >> designation;
	cout << "Grade: " << endl;
	cin >> grade;
	cout << "Loan: " << endl;
	cin >> loan;

}

void Employee::modify_record(int, char[], char[], char[], char[], char, char, char, float, float)
{
	//user can modify existing record
	//ask for employee code

		//get employee record

		//edit employee record
		//save employee record
}

void Employee::delete_record(int)
{
	//deletes employee record via employee code

	//ask for employee code

	//comfirmation message if user really wants to delete

}

int Employee::lastcode(void)
{


}


int Employee::recordnum(int)
{


}

void Employee::display_record(int)
{ //displays employee record


}

bool Employee::validDate(int, int, int)
{ //valid date in M/DD/YY
	int month;
	int day;
	int year;

}