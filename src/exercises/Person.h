#pragma once

#include <string>

struct Person {
	std::string name;
	std::string address;

	//defined here will expand inline
	std::string name() const { return name; }
	std::string address() const { return address; }
};