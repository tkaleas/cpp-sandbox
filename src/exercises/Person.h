#pragma once

#include <string>

struct Person;
std::istream &read(std::istream& s, Person& p);

struct Person {

	Person() : name(""), address("") {};
	Person(const std::string n, const std::string a) : name(n), address(a) {};
	Person(const std::string n) : Person(n,"") {};
	Person(std::istream &is) {
		read(is, *this);
	}

	std::string name;
	std::string address;

	//defined here will expand inline
	std::string name() const { return name; }
	std::string address() const { return address; }
};

std::ostream &print(std::ostream& o, const Person& p) {
	o << p.name << " " << p.address << " " ;
	return o;
}

std::istream &read(std::istream& s, Person& p) {
	s >> p.name >> p.address;
	return s;
}