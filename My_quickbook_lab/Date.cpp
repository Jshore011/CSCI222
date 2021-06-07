#include "Date.h"
#include "Employee.h"

using namespace std;

void Date::iniMonths()
{
	months.push_back("January");
	months.push_back("February");
	months.push_back("March");
	months.push_back("April");
	months.push_back("May");
	months.push_back("June");
	months.push_back("July");
	months.push_back("August");
	months.push_back("September");
	months.push_back("October");
	months.push_back("November");
	months.push_back("December");
}

Date::Date()
{
	//stdmonths =  {"January", "February", "March","March","May","June","July", "August","September","October","November","December"};
	
	iniMonths();
	month = day = year = 0;
}

Date::Date(int inMonth, int inDay, int inYear)
{
	month = inMonth;
	day = inDay;
	year = inYear;
	iniMonths();
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}

void Date::setMonth(int month)
{
	//setter for month
	this->month = month;
}

void Date::setDay(int day)
{
	//setter for day
	this->day = day;
}

void Date::setYear(int year)
{
	//setter for year
	this->year = year;

}

string Date::toString(bool printStrings)
{
	string dateString = "";
	if (printStrings)
	{
		dateString = months[month - 1];
	}
	else
		dateString = to_string(month);

	dateString += " ";
	dateString += to_string(day);

	dateString += ", ";
	dateString += to_string(year);

	return dateString;
}