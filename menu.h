#pragma once

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <fstream>

extern double total_amount;

void welcome();
void menu(std::fstream& file);
void beverages(std::fstream& file);
void breakfast(std::fstream& file);
void burgers(std::fstream& file);
void snacks_and_sides(std::fstream& file);
void show_cart();
void print_receipt();

#endif
