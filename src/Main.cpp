/**
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <cstdio>

#include "catch.hpp"
#include "Utils/Time.h"

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
    
	return 0;
}
