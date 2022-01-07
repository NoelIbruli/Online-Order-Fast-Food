#include <iostream>
#include <fstream>
#include <cstdio>

#include "menu.h"

int main()
{
	std::fstream file;
	file.open("cart.txt", std::ios::out);

	if (file.is_open())
	{
		file << "---------------------------------------------------------------\n";
		file << "|Name\t\t\t|Quantity\t|Price\t\t|Total|\n";
		file << "---------------------------------------------------------------\n\n";
		file.close();
	}


	system("clear");	
	welcome();
	system("clear");
	
	menu(file);
	system("clear");
	print_receipt();
	
	return 0;
}
