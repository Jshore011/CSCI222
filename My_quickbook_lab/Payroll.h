#pragma once


class Payroll
{
public:
	
	Payroll();
	void displayEmployeeRecord(int);
	void displayAllEmployees();
	void printSalarySlip(void);

	

private:
	void modEmployee(int);
	void removeById(int);


};