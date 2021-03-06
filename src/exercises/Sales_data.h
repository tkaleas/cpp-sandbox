#pragma once

#ifndef SALES_DATA_H 
#define SALES_DATA_H

#include <string>

using namespace std;

struct Sales_data {

public:
	friend std::istream &read(std::istream& s, Sales_data& data);
	friend std::ostream &print(std::ostream& o, const Sales_data& data);

	//Operator Friends
	friend Sales_data& operator+(Sales_data& lhs, Sales_data& rhs);
	//Output
	friend std::ostream& operator<<(std::ostream &os, const Sales_data &d);
	//Input
	friend std::istream& operator>>(std::istream &is, Sales_data &d);

	Sales_data & operator+=(const Sales_data &rhs);

	Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {};
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned int n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream &is) {
		read(is, *this);
	}

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& data);

	double avg_price() const { return revenue / units_sold; };

private:
	std::string bookNo; 
	unsigned units_sold;
	double revenue;
};

//OPERATOR OVERLOADING

Sales_data & Sales_data::operator+=(const Sales_data &rhs) {
	this->units_sold += rhs.units_sold;
	this->revenue += rhs.revenue;
	return *this;
}

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

std::ostream & operator<<(std::ostream & os, const Sales_data & d)
{
	os << "(" << d.isbn() << "," <<d.units_sold << "," << d.avg_price() << ")";
	return os;
}

std::istream & operator>>(std::istream & is, Sales_data & d)
{
	double price;
	is >> d.bookNo >> d.units_sold >> price;
	if (is)
		d.revenue = d.units_sold*price;
	else
		d = Sales_data();
	return is;
}

std::istream &read(std::istream& s, Sales_data& data) {
	float price;
	s >> data.bookNo >> data.units_sold >> price;
	data.revenue = data.units_sold * price;
	return s;
}

#endif
