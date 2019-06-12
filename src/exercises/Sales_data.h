#pragma once

#ifndef SALES_DATA_H 
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& data);

	std::string bookNo; 
	unsigned units_sold = 0;
	double revenue = 0.0;
}; 

//Member Definitions
Sales_data& Sales_data::combine(const Sales_data& data) {
	this->revenue += data.revenue;
	this->units_sold += data.units_sold;

	return *this;
}

//Extra Operations
// nonmember Sales_data interface functions
Sales_data add(const Sales_data &a, const Sales_data &b) {
	Sales_data sdata = a;
	sdata.combine(b);
	return sdata;
}

std::ostream &print(std::ostream& o, const Sales_data& data) {
	o << data.bookNo << " " << data.units_sold << " " << data.revenue << " ";
	return o;
}

std::istream &read(std::istream& s, Sales_data& data) {
	float price;
	s >> data.bookNo >> data.units_sold >> price;
	data.revenue = data.units_sold * price;
	return s;
}

#endif
