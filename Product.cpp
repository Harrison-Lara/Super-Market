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
#include "Food.h"
using namespace std;

//constructors
Product::Product() :Product(-1, "") { } // defaults set 

Product::Product(int bar_code, string full_name)
{
	if (bar_code <= 0)
	{
		barcode = -1; // sets barcode to -1 if not there
	}
	else
	{
		barcode = bar_code; // sets barcode to a variable if there
	}

	name = full_name; // setting variables 
	price = -1; // setting placement
	tax = .09; // set amount for tax
}

void main(); // decalre main

//defining getters 
int Product::grab_barcode() { return barcode; } // define grab barcode to new variable

double Product::grab_price() { return price; }// define grab price to new variable

string Product::grab_name() { return name; }// define grab name to new variable

double Product::grab_discount() { return discount; }// define grab discount to new variable

double Product::grab_tax() { return tax; }// define grab tax to new variable

// defining setters
void Product::set_barcode(int bar_num) { barcode = bar_num; } // define set barcode to new variable

void Product::set_price(double food_price) {price = food_price; }// define set price to new variable

void Product::set_name(string food_name) { name = food_name; }// define set name to new variable

void Product::set_discount(double coupon) { discount = coupon; }// define set discount to new variable

void Product::set_tax(double gov) { tax = gov; }// define set tax to new variable

// defining functions
void Product::update(ofstream &output) { return; }// define update function