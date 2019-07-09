// Harrison Lara
// May ZeinelDin
// March 5, 2017

// includes
#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
#include<sstream>
#include "Product.h"
#include "Food.h"
#include "Electronic.h"
using namespace std;

void main() 
/* This function is the main program will take functions from all the classes to 
output the correct data from what the user wants to choose from according to their
input from the menu*/
{
	ofstream outfile; // open output file
	outfile.open("Output.txt");

	string input; // string variable for menu input
	cout << "\nWelcome to our Supermarket!" << endl; // greet user
	cout << "----------------------------" << endl; // formatting

	menu_options(); // display menu options for user

	do
	{
		input = get_input(); // set variable to function for menu selections

		if (input == "1") // output the Food Inventory
		{
			
			outfile << "------------------------ Food Inventory ------------------------"; // Food Inventory header outputted
			&Food::read_data;// calling functions to read data and output for Food class
			&Food::update;
		}	
		else if (input == "2") // output the Electronics Inventory
		{
			outfile << "------------------------ Electronics Inventory ------------------------"; // Electronics Inventory header outputted
			&Electronic::read_data; // calling functions to read data and output for Electronics class
			&Electronic::update;
		}
		else if (input == "3") // output the Electronics and Food Inventory
		{
			outfile << "------------------------ Food Inventory ------------------------\n"; //Food and Electronics Inventory headers outputted
			&Food::read_data;// calling functions to read data and output for Food class
			&Food::update;

			outfile << "\n------------------------ Electronics Inventory -----------------";
			&Electronic::read_data;// calling functions to read data and output for Electronics class
			&Electronic::update;
		}
		else if (input == "4") // exit program
		{
			cout << "\n" << "Ending program..." << endl; // tell user program is closing
			exit(1);
		}
		if (input != "4") // input is not 4, then display restart menu
		{
			string next; // string variable for restart menu
			cout << "\n" << "---------------------------------------------------------"; // output to user if they want to return to the menu or exit
			cout << "\n" << "Would you like to return to main menu? [y: yes	| n: no] : ";
			cin >> next; // take in user input
			if (next == "y") // input is yes
			{
				menu_options(); // display menu again
			}
			else if (next == "n") // input is no
			{
				cout << "\n" << "Ending program..." << endl; //tell user program is closing
				exit(1); // exit program
			}
		}
	} 
	while (input != "4"); // if input is not 4, ask for input again

	outfile.close();// close file
}