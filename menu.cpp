#include "menu.h"
#include <cstdlib>
#include <fstream>

double total_amount = 0; // global in to assign the total value of all products bought

void print_receipt()
{
	system("clear");
	std::cout << "---------------------------------------------------------------\n";
	std::cout << "Online Shop\n";
	std::cout << "---------------------------------------------------------------\n\n\n";
	std::ifstream cartFile;

        std::string content;
        cartFile.open("cart.txt");

        if(cartFile.is_open())
        {
                while (!cartFile.eof())
                {
                        getline(cartFile, content);
                        if(cartFile.good())
                        {
                                std::cout << content << std::endl;
                        }
                }
                cartFile.close();
        }
        else
                std::cerr << "Hey Error!";

	std::cout << "Total amount to pay: " << total_amount  << "$" << std::endl;
}

void show_cart()
{
	std::ifstream cartFile;

	std::string content;
	cartFile.open("cart.txt");
	
	if(cartFile.is_open())
	{
		while (!cartFile.eof())
		{
			getline(cartFile, content);
			if(cartFile.good())
			{
				std::cout << content << std::endl;
			}
		}
		cartFile.close();
	}
	else
		std::cerr << "Hey Error!";
}

void snacks_and_sides(std::fstream& file)
{
	int pickSnacks;
	double friesPrice = 2.01, appleSlicesPrice = 1;
	int fries = 0, appleSlices = 0;
	
	file.open("cart.txt", std::ios::app); // open file in append mode
	
	if(file.is_open())
	{
		system("clear");
        	do
        	{
                	std::cout << "Choose from the options below\n\n\n";
                	std::cout << "1. Fries\n";
                	std::cout << "2. Apple Slices\n";
			std::cout << "3. Main Menu\n";
			std::cout << "4. Show Cart\n";
                	std::cout << "0. Exit\n";
                	std::cout << "Enter: ";
                	std::cin >> pickSnacks;
	
        	        switch(pickSnacks)
        	        {
				case 0:
					print_receipt();
					exit(0);
					break;
        	                case 1:
        	                        ++fries;
        	                        std::cout << "You have " << fries << " fries in your cart.\n";
					file << " Fries\t\t\t " << fries << "\t \t " << friesPrice << "$\t\t " << friesPrice * fries << "$"  << std::endl;
					total_amount += friesPrice * fries;
        	                        break;
        	                case 2:
        	                        ++appleSlices;
                	                std::cout << "You have " << appleSlices << " Apple Slices in your cart.\n";
					file << " Apple Slice\t\t\t " << appleSlices << "\t \t " << appleSlicesPrice << "$\t\t " << appleSlicesPrice * appleSlices << "$"  << std::endl;
                        	        total_amount += appleSlicesPrice * appleSlices;
					break;
                        	case 3:
                        	        system("clear");
                                	menu(file);
                                	break;
				case 4:
					system("clear");
					show_cart();
					break;
                	}
        	}while(pickSnacks);
		file.close();
	}
	else
		std::cout << "Error!\n";
}

void burgers(std::fstream& file)
{
	file.open("cart.txt", std::ios::app); // open file in append mode

	int pickBurger;
	double bigMacPrice = 4.89, mcDoublePrice = 2.19, cheeseBurgerPrice = 1.69, hamburgerPrice = 1.59, doubleCheeseBurgerPrice = 2.39;
	int bigMac = 0, mcDouble = 0, cheeseBurger = 0, hamburger = 0, doubleCheeseBurger = 0;
	std::string macBig = "BigMac";
	if (file.is_open())
	{
		system("clear");
        	do
        	{
        	        std::cout << "Choose from the options below\n\n\n";
        	        std::cout << "1. Big Mac\n";
        	        std::cout << "2. McDouble\n";
        	        std::cout << "3. Cheese Burger\n";
        	        std::cout << "4. Hamburger\n";
        	        std::cout << "5. Double Cheeseburger\n";
			std::cout << "6. Main Menu\n";
			std::cout << "7. Show Cart\n";
        	        std::cout << "0. Exit\n";
        	        std::cout << "Enter: ";
        	        std::cin >> pickBurger;
	
	                switch(pickBurger)
        	        {
				case 0:
					print_receipt();
					exit(0);
					break;
        	                case 1:
        	                        ++bigMac;
        	                        std::cout << "You have " << bigMac << " Big Macs in cart.\n\n";
					file << " BigMac\t\t\t " << bigMac << "\t \t " << bigMacPrice << "$\t\t " << bigMacPrice * bigMac << "$"  << std::endl;
					total_amount += bigMacPrice * bigMac;
					break;
        	                case 2:
        	                        ++mcDouble;
        	                        std::cout << "You have " << mcDouble << " McDoubles in cart.\n\n";
					file << " McDouble\t\t " << mcDouble << "\t \t " << mcDoublePrice << "$\t\t " << mcDoublePrice * mcDouble << "$"  << std::endl;
                                	total_amount += mcDoublePrice * mcDouble;
					break;
               	        	case 3:
                        	        ++cheeseBurger;
                        	        std::cout << "You have " << cheeseBurger << " Cheeseburgers in cart.\n\n";
					file << " CheeseBurger\t\t " << cheeseBurger << "\t \t " << cheeseBurgerPrice << "$\t\t " << cheeseBurgerPrice * cheeseBurger << "$"  << std::endl;
                        	        total_amount += cheeseBurgerPrice * cheeseBurger;
					break;
                        	case 4:
                        	        ++hamburger;
                        	        std::cout << "You have " << hamburger << " Hamburgers in cart.\n\n";
					file << " Hamburger\t\t " << hamburger << "\t \t " << hamburgerPrice << "$\t\t " << hamburgerPrice * hamburger << "$"  << std::endl;
                        	        total_amount += hamburgerPrice * hamburger;
					break;
                        	case 5:
                        	        ++doubleCheeseBurger;
                        	        std::cout << "You have " << doubleCheeseBurger << " Double Cheeseburgers in cart.\n\n";
					file << " Double CheeseBurger\t " << doubleCheeseBurger << "\t \t " << doubleCheeseBurgerPrice << "$\t\t " << doubleCheeseBurgerPrice * doubleCheeseBurger << "$"  << std::endl;
                        	        total_amount += doubleCheeseBurgerPrice * doubleCheeseBurger;
					break;
                        	case 6:
                        	        system("clear");
                        	        menu(file);
                                	break;
				case 7:
					system("clear");
					show_cart();
					break;
                	}
        	}while(pickBurger);
		file.close();
	}
	else
		std::cout << "Error!\n";
}

void breakfast(std::fstream& file)
{
	file.open("cart.txt", std::ios::app); // open file in append mode
	
	int pickBreakfast;
	double hotcakesPrice = 3.89, mcMuffinPrice = 4.59, baconEggCheesePrice = 5.12, sausagePrice = 3.92, bigBreakfastPrice = 6.78;
	int hotcakes = 0, mcMuffin = 0, baconEggCheese = 0, sausage = 0, bigBreakfast = 0;
	
	if(file.is_open())
	{
		system("clear");
        	do
        	{
        	        std::cout << "Choose from the options below\n\n\n";
        	        std::cout << "1. Hotcakes\n";
        	        std::cout << "2. McMuffin\n";
        	        std::cout << "3. Bacon Egg Cheese\n";
        	        std::cout << "4. Sausage\n";
        	        std::cout << "5. Big Breakfast\n";
			std::cout << "6. Main Menu\n";
			std::cout << "7. Show Cart\n";
        	        std::cout << "0. Exit\n";
        	        std::cout << "Enter: ";
        	        std::cin >> pickBreakfast;
	
	                switch(pickBreakfast)
	                {
				case 0:
					print_receipt();
					exit(0);
					break;
	                        case 1:
	                                ++hotcakes;
	                                std::cout << "You have " << hotcakes << " hotcakes in cart.\n\n";
					file << " Hotcakes\t\t " << hotcakes << "\t \t " << hotcakesPrice << "$\t\t " << hotcakesPrice * hotcakes << "$"  << std::endl;
	                                total_amount += hotcakesPrice * hotcakes;
					break;
	                        case 2:
	                                ++mcMuffin;
	                                std::cout << "You have " << mcMuffin << " McMuffins in cart.\n\n";
					file << " McMuffin\t\t " << mcMuffin << "\t \t " << mcMuffinPrice << "$\t\t " << mcMuffinPrice * mcMuffin << "$"  << std::endl;
	                                total_amount += mcMuffinPrice * mcMuffin;
					break;
	                        case 3:
	                                ++baconEggCheese;
	                                std::cout << "You have " << baconEggCheese << " BaconEggChees in cart.\n\n";
					file << " BaconEggCheese\t\t " << baconEggCheese << "\t \t " << baconEggCheesePrice << "$\t\t " << baconEggCheesePrice * baconEggCheese << "$"  << std::endl;
	                                total_amount += baconEggCheesePrice * baconEggCheese;
					break;
	                        case 4:
	                                ++sausage;
	                                std::cout << "You have " << sausage << " Sausages in cart.\n\n";
					file << " Sausage\t\t " << sausage << "\t \t " << sausagePrice << "$\t\t " << sausagePrice * sausage << "$"  << std::endl;
	                                total_amount += sausagePrice * sausage;
					break;
	                        case 5:
	                                ++bigBreakfast;
	                                std::cout << "You have " << bigBreakfast << " Big Breakfasts in cart.\n\n";
					file << " Big Breakfast\t\t " << bigBreakfast << "\t \t " << bigBreakfastPrice << "$\t\t " << bigBreakfastPrice * bigBreakfast << "$"  << std::endl;
	                                total_amount += bigBreakfastPrice * bigBreakfast;
					break;
	                        case 6:
        	                        system("clear");
	                                menu(file);
        	                        break;
				case 7:
					system("clear");
					show_cart();
					break;

                	}
        	}while(pickBreakfast);
		file.close();
	}
	else
		std::cout << "Error!\n";
}

void beverages(std::fstream& file)
{
        int pickBeverage;
	double colaPrice = 1.48, spritePrice = 1.32, pepperPrice = 1.17, fantaPrice = 1.50, dietCokePrice = 1.33, waterPrice = 1.00;
        static int cola = 0, sprite = 0, pepper = 0, fanta = 0, dietCoke = 0, water = 0; // needs to be static or global (decide later)
	file.open("cart.txt", std::ios::app); // open file in append mode

	if(file.is_open())
	{
		system("clear");
        	do
        	{
        	        std::cout << "Choose from the options below\n\n\n";
        	        std::cout << "1. Coca Cola\n";
        	        std::cout << "2. Sprite\n";
        	        std::cout << "3. Dr Pepper\n";
               		std::cout << "4. Fanta Orange\n";
                	std::cout << "5. Diet Coke\n";
                	std::cout << "6. Water\n";
			std::cout << "7. Main Menu\n";
			std::cout << "8. Show Cart\n";
                	std::cout << "0. Exit\n";
                	std::cout << "Enter: ";
                	std::cin >> pickBeverage;
	
	                switch(pickBeverage)
	                {
				case 0:
					print_receipt();
					exit(0);
					break;
	                        case 1:
	                                ++cola;
                                	std::cout << "You have " << cola << " Colas in cart.\n";
					file << " Cola\t\t\t " << cola << "\t \t " << colaPrice << "$\t\t " << colaPrice * cola << "$"  << std::endl;
        	                        total_amount += colaPrice * cola;
					break;
        	                case 2:
        	                        sprite++;
       	                         	std::cout << "You have " << sprite << " Sprites in cart.\n";
					file << " Sprite\t\t\t " << sprite << "\t \t " << spritePrice << "$\t\t " << spritePrice * sprite << "$"  << std::endl;
       	                         	total_amount += spritePrice * sprite;
					break;
                        	case 3:
       	                        	pepper++;
                                	std::cout << "You have " << pepper << " Dr.Peppers in cart.\n";
					file << " DrPepper\t\t " << pepper << "\t \t " << pepperPrice << "$\t\t " << pepperPrice * pepper << "$"  << std::endl;
                                	total_amount += pepperPrice * pepper;
					break;
                        	case 4:
                        	        fanta++;
                        	        std::cout << "You have " << fanta << " Fanta Orange in cart.\n";
					file << " Fanta\t\t\t " << fanta << "\t \t " << fantaPrice << "$\t\t " << fantaPrice * fanta << "$"  << std::endl;
                        	        total_amount += fantaPrice * fanta;
					break;
                        	case 5:
                        	        dietCoke++;
                        	        std::cout << "You have " << dietCoke << " Diet Cokes in cart.\n";
					file << " Diet Coke\t\t " << dietCoke<< "\t \t " << dietCokePrice << "$\t\t " << dietCokePrice * dietCoke << "$"  << std::endl;
                        	        total_amount += dietCokePrice * dietCoke;
					break;
                        	case 6:
                        	        water++;
                        	        std::cout << "You have " << water << " water in cart.\n";
					file << " Water\t\t\t " << water << "\t \t " << waterPrice << "$\t\t " << waterPrice * water << "$"  << std::endl;
                        	        total_amount += waterPrice * water;
					break;
                        	case 7:
                        	        system("clear");
					file.close();
                        	        menu(file);
                        	        break;
				case 8:
					system("clear");
					show_cart();
					break;
			}
        	}while(pickBeverage);
		file.close();
	}
	else
		std::cout << "Error!\n";
}

void menu(std::fstream& file)
{
        int category;
	
        std::cout << "Our Menu\n\n\n";
        std::cout << "1. Beverages\n";
        std::cout << "2. Breakfast\n";
        std::cout << "3. Burgers\n";
        std::cout << "4. Snacks and Sides\n";
        std::cout << "0. Exit\n\n";
        std::cout <<"Enter: ";
        std::cin >> category;

        switch(category)
        {
		case 0:
			print_receipt();
			exit(0);
			break;
                case 1:
                        beverages(file);
                        break;
                case 2:
                        breakfast(file);
                        break;
                case 3:
                        burgers(file);
                        break;
                case 4:
                        snacks_and_sides(file);
                        break;
        }
}

void welcome()
{
	std::string key;
	std::cout << "Welcome to our Online Shop\n\n\n";
        std::cout << "Press any key to continue . . .\n";
	getline(std::cin, key);
}
