// Harrison Lara
// May ZeinelDin
// March 5, 2017

// includes
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Product.h"
#include "Food.h"
using namespace std;

// constructors
Food::Food() :Product() { -1, ""; };

Food::Food(string date, int days) { }

// defining getters
int Food::grab_days() { return days; } // define grab days to new variable

string Food::grab_date() { return date; } // define grab date to new variable

// defining setters
void Food::set_date(string dates) { date = dates; }  // define set date to new variable

void Food::set_days(int day) { days = day; } // define set days to new variable

// defining functions
void Food::update(ofstream &output, int days, Food& e) 

/* this function checks for day amount and then sets discount pending on days, applies the discount to the price 
Following this action, the function then outputs to the file with the desired results for food inventory */

{
	if (days < 10) // less than ten days
	{
		discount = price; // no change to price
	}
	else if ( days >= 10 && days <= 14) // days are 10 to 14
	{
		discount = price * .20; // 20% off price
	}
	else if (days >= 15 && days <= 30) // days are 15 to 30
	{
		discount = price * .50; // 50% off price
	}
	else
	{
		discount = price * .80; // days are over 30, then 80% off price
	}

	ofstream output_file; // opening output file
	output_file.open("Output.txt");

	// outputting to the file
	output_file << e.grab_name() << "with Barcode:"  <<"\n";
	output_file << e.grab_barcode() << "its price: " << e.grab_price() * discount << " and was produced on " << e.grab_date() << "\n";
	output_file << "The final price is now" << price << " with a discount of: " << discount;

	output_file.close();// close file
}

bool Food ::read_data(ifstream& food_file,/*const*/ Food& e)
/* This function opens the desired file to read and grab the proper data from to use throughout the program for the food portion*/
{
	ifstream food_files; // opening food file
	food_files.open("Food.txt");

	const int max_name_length = 11; // setting max amount of characters for food name
	const int max_date_length = 10; // setting max amount of characters for date 

	int bar_num; //barcode variable
	string food_name; // food name variable
	double food_price; // price variable
	string food_date; // date variable
	int food_days; // amount of days variable

	char FOOD_NAME[max_name_length] = { '\0' }; // creating arrays for the max character variables for food name and date
	char FULL_DATE[max_date_length] = { '\0' };

	//barcode
	food_files >> bar_num; // food file takes in barcode
	e.set_barcode(bar_num); // setter getting barcode
	food_files.ignore(); // ignores rest of data

	// food name
	food_files.getline(FOOD_NAME, max_name_length, '\n'); // getline grabs the foods name
	food_name.assign(FOOD_NAME); // set food name to pre variable
	e.set_name(food_name); // setter gets name from pre variable
	food_files.ignore();// ignores rest of data

	//price
	food_files >> food_price; // food file grabs the price
	e.set_price(food_price); // setters takes the price
	food_files.ignore();// ignores rest of data

	// date
	food_files.getline(FULL_DATE, max_date_length, '\n'); // getline grabs the date
	food_date.assign(FULL_DATE); // set food to pre variable
	e.set_date(food_date); // setter takes date from pre variable
	food_files.ignore();// ignores rest of data

	// days
	food_files >> food_days; // food file getting amount of days
	e.set_days(food_days); // setter takes the days 
	food_files.ignore();// ignores rest of data

	return 0;
	food_files.close(); // close file
}