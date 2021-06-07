#pragma once
#include <string>
#include <string.h>
#include <vector>
using namespace std;

class Date
{
private:
	int month;
	int day;
	int year;
	
	vector<string> months;
	void iniMonths();

public:
	Date();
	Date(int, int, int);
	int getMonth();
	int getDay();
	int getYear();
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	string toString(bool printStrings = true);
	
};

