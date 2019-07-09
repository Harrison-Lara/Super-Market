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
#include "Electronic.h"
using namespace std;

// constructors
Electronic::Electronic() :Electronic(-1) { } // defaults set 

Electronic::Electronic(int warranty) { ; }

//defining getters
int Electronic::get_warranty() { return warranty; } // getter setting to new variable

// defining setters
void Electronic::set_warranty(int length) { warranty = length;} //setter setting to new variable

//defining fuctions
void Electronic::update(ofstream &output, int warranty, double price, Electronic& e)

/* this function checks for price amount and then sets warranty pending on price, applies the warrenty to the product
Following this action, the function then outputs to the file with the desired results for electronics inventory */

{
	ofstream outputs; // opening the output file
	outputs.open("Output.txt");
	if (price < 200) // price less than $200
	{
		warranty = 1; // gets one year warranty
		outputs << e.grab_name() << " with barcode: " << e.grab_barcode(); // outputting data to file
		outputs << "Will have a warrenty of " << warranty << "years";
		outputs << "Full price is " << price;
		outputs << "No financing available";
	}
	else if (price >= 200 && price <= 1000) // price is 200 to 1000
	{
		warranty = 3;// gets three year warranty
		outputs << e.grab_name() << " with barcode: " << e.grab_barcode();
		outputs << "Will have a warrenty of " << warranty << "years and the price is " << price; // outputting data to file
		outputs << "Option 1: You can pay in cash \n";
		outputs << "Option 2: You can finance over 12 months with your total price of: " << price;
	}
	else
	{
		warranty = 5;// gets 5 year warranty
		outputs << e.grab_name() << " with barcode: " << e.grab_barcode();
		outputs << "Will have a warrenty of " << warranty << "years and the price is " << price;// outputting data to file
		outputs << "Option 1: You can pay in cash \n";
		outputs << "Option 2: You can finance over 24 months with your total price of: " << price;
	}
	outputs.close(); // close file
}

bool Electronic::read_data(istream* electronic_file, int barcode, string name, double price, /*const*/ Electronic& e)
/* This function opens the desired file to read and grab the proper data from to use throughout the program for the electronics portion*/
{ 
	ifstream electronic_files; // opening electronics file
	electronic_files.open("Electronics.txt");

	if ((*electronic_file) >> barcode && (*electronic_file) >> name && (*electronic_file) >> price) // taking in data in order
	{
		return true;
	}
	return false;

	const int max_product_length = 11; // setting max name length for the product

	int barcodes; // create variables for functions
	string product;
	double pricing;

	char product_name[max_product_length] = { '\0' }; // set variable for array of products max name length

	//barcode
	electronic_files >> barcodes; // taking in the barcode
	e.set_barcode(barcodes); // setter takes the barcode
	electronic_files.ignore();// ignores rest of data

	//name
	electronic_files.getline(product_name, max_product_length, '\n'); // getline grabs the name and places in array
	product.assign(product_name); // name is given to pre variable
	e.set_name(product); // setter gets name from pre variable
	electronic_files.ignore();// ignores rest of data

	// price
	electronic_files >> pricing; // taking in the price
	e.set_price(pricing); // setters gets the price
	electronic_files.ignore();// ignores rest of data

	electronic_files.close(); // close file
}

static float Interest( double price, double tax) 
/* This function calculates the end for the price after tax, monthly payments*/
{
	double taxed = (price * tax) + price; // adds in tax
	double total_one = ((taxed * 1.1)/12); // monthly payment for 12 months (formula simplified)
	double total_two = ((taxed* 1.21 / 12)); // monthly payment for 24 months (formula simplified)
}