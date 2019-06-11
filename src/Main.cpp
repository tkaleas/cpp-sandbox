/**
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <cstdio>

#include "catch.hpp"
#include "Utils/Time.h"
#include <iostream>
#include "exercises_1.h"

int main() {
    using Utils::Time;

    time_t startUs = Time::getTickUs();
    // Do something in a few us ...
	printf("Hello World! \n");
	time_t endUs   = Time::getTickUs();
    time_t deltaUs = Time::diff(startUs, endUs);
    printf("elapsed time: %I64u\n", deltaUs);

    time_t startMs = Time::getTickMs();
    // Do something in a few ms...
	printf("Hello World 2! \n");
    time_t endMs   = Time::getTickMs();
    time_t deltaMs = Time::diff(startMs, endMs);
    
	printf("elapsed time: %llu\n", deltaMs);
	std::cout << std::endl << std::endl;

	//C++ Primer Exercise Executions
	std::cout << "Exercises" << std::endl << std::endl;

	//exercise1_3();
	//exercise1_4();
	//exercise1_5();
	exercise1_6();
	//exercise2_3();

	//exercise_3_16();
	//exercise_3_35();

	//std::cout <<"Fact:" << fact(0) << std::endl;

	//std::cout << "Fact:" << fact(1) << std::endl;

	//std::cout << "Fact:" << fact(5) << std::endl;

	//std::cout << "Fact:" << fact(15) << std::endl;


	//std::cout << "Se:" << sequencer() << std::endl;

	//std::cout << "Se:" << sequencer() << std::endl;

	//std::cout << "Se:" << sequencer() << std::endl;

	//Wait for Input Before Exiting
	int a;
	std::cin >> a;

	return 0;
}
