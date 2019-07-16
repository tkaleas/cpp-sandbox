#pragma once

#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; };
	virtual double net_price(std::size_t n) const { return n * price; };
	virtual ~Quote() = default;

private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price, std::size_t size, double discount);
	double net_price(std::size_t n) const override;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book,
	double sales_price,
	std::size_t size,
	double discount) :
	//Note Initialization of Base Class Here
	Quote(book,sales_price), min_qty(size), discount(discount) {}

double Bulk_quote::net_price(std::size_t n) const {
	if (n >= min_qty)
		return n * (1.-discount) * price;
	else
		return n * price;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "Isbn:" << item.isbn() << " # sold:" << n << "total due: " << ret << std::endl;
	return ret;
}