#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <sstream>
#include <iostream>

//Some Trivial Tests to make sure Catch is working correctly. 

TEST_CASE( "Testing Hello World Direct Write" ) {
    std::ostringstream out;

	std::string helloString = "Hello World";

	out.write(helloString.c_str(),helloString.size());

    // Catch Testing Structure
    REQUIRE( out.str() == "Hello World");

}

TEST_CASE("Testing Hello World Redirect String Stream") {
	std::ostringstream out;
	std::streambuf* coutbuf = std::cout.rdbuf();

	std::cout.rdbuf(out.rdbuf()); //redirect cout to out
	std::cout << "Hello World" << std::endl;
	std::cout.rdbuf(coutbuf);

	// Catch Testing Structure
	REQUIRE(out.str() == "Hello World\n");

}