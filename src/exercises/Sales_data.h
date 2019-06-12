#pragma once

#ifndef SALES_DATA_H 
#define SALES_DATA_H

#include <string> 
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
	this->units_sold += data.revenue;

	return *this;
}

//Extra Operations
#endif