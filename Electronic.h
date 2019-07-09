// Harrison Lara
// May ZeinelDin
// March 5, 2017

#pragma once
#ifndef MY_ELECTRONIC
#define MY_ELECTRONIC

// includes
#include <string>
#include <fstream>
#include <iostream>
#include<string>
#include"Product.h"
using namespace std;

class Electronic : public Product //derived class from Product class
{
public:

	//getters
	int get_warranty(); // gets the warranty

	//setters
	void set_warranty(int length); // sets the warranty

	//constructor
	Electronic(int warranty); // defaults for constructor
	Electronic();

	// declaring functions
	bool read_data(istream * electronic_file, int barcode, string name, double price, /*const*/ Electronic& e); // reads files and gets data
	void update(ofstream &output, int warranty, double price, Electronic& e); // redefining update function for output

private:

	int warranty; // create warranty variable

};
#endif