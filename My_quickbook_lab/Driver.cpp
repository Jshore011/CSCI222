
#include "Menu.h"
#include "Employee.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

int main(int arg, char* argv[])
{
	//runs program
	Menu menu = new menu;

	for (int i = 0; i < 7; i++)
	{
		menu.displayMenu();
	}
	menu.getSelection();



	return 0;
}