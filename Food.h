// Harrison Lara
// May ZeinelDin
// March 5, 2017

#pragma once
#ifndef MY_FOOD
#define MY_FOOD

// includes
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

class Food :public Product // derived class
{
public:

	//constructor
	Food(string date, int days);
	Food();

	//getters
	string grab_date(); // gets date
	int grab_days(); // gets amount of days

	//setters
	void set_date(string food_dates); // sets date
	void set_days(int food_days); // sets amount of days

	//functions
	void update(ofstream &output, int days, Food& e); // redefining update function
	bool read_data(ifstream& food_file,/*const*/ Food& e); // redefining read data function

private:

	string date; //create variable for date
	int days; // create variable for days

};
#endif