
#pragma once
#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include "Date.h"

class Employee
{
public:
	Employee();
	~Employee();
	void modification(void);
	
	
private:
	void add_record(int, char[], char[], char[], int, int, int, char[], char, char, char, float, float);
	void modify_record(int, char[], char[], char[], char[], char, char, char, float, float);
	void delete_record(int);
	int lastcode(void);
	int recordnum(int);
	bool validDate(int, int, int);



	
	int empCode;
	Date joinDate;
	char name[26], address[31], phone[10], designation[16];
	char grade, house, conv;
	float loan, salary, houseAllowance;
};