// Harrison Lara
// May ZeinelDin
// March 5, 2017

// header defaults
#pragma once
#ifndef MY_PRODUCT
#define MY_PRODUCT

// includes
#include <fstream>
#include <iostream>
#include<string>
using namespace std;

class Product // parent class
{
public:

	//getters
	int grab_barcode(); //gets barcode
	double grab_price();//gets price
	double grab_discount();//gets discount 
	double grab_tax();//gets tax
	string grab_name();//gets name of item

	//setters
	void set_name(string full_name); // set name 
	void set_price(double cost);// set price
	void set_barcode(int bar_code);// set barcode
	void set_discount(double coupon);// set discount
	void set_tax(double gov);// set tax

	// constructors
	Product(int barcode, string full_name); 
	Product();

	void update(ofstream &output); // update function

	double price, tax, discount; // price, tax and discount variables
	int barcode;// barcode variable
	string name; // name variable

private:
	
};
#endif

static void menu_options() // display menu options for the user
{
	cout << "\nWhich department would you like to check? \n" << endl;
	cout << "(1) Food" << endl;
	cout << "(2) Electronics" << endl;
	cout << "(3) Food and Electronics" << endl;
	cout << "(4) Exit" << "\n" << endl;
}

static string get_input() // take input
{
	string input;// string variable for input

	do
	{
		cout << "Please enter your selection: " << endl; 
		cin >> input;
		if (input != "1"&& input != "2" && input != "3" && input != "4") // checks if input if valid
		{
			cout << "Error, input not valid!" << endl; // error message if input is not valid
		}
	} while (input != "1"&& input != "2" && input != "3" && input != "4"); // repeat menu if not 1-4 selected

	return input;
}