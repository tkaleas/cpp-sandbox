#pragma once


#include <iostream>

#include "Sales_item.h"

//C++ Primer Exercises 1.2
static void exercise1_3() {
	std::cout << "Hello World!" << std::endl;
}

static void exercise1_4() {
	std::cout << "5*2="<< 5*2 << std::endl;
}

static void exercise1_5() {
	int v1 = 5;
	int v2 = 3;
	std::cout << "The sum of ";
	std::cout << v1;
	std::cout << " and ";
	std::cout << v2;
	std::cout << " is ";
	std::cout << v1 + v2;
	std::cout << std::endl;
}

static void exercise1_7() {
	std::cout << "/*";
	std::cout << "*/";
}

static int exercise1_9() {
	int n = 50;
	int sum = 0;
	while (n <= 100) {
		sum += n;
		sum++;
	}
	return sum;
}

static void exercise1_10() {
	int n = 10;
	while (n >= 0) {
		std::cout << n << std::endl;
		n--;
	}
}

static int exercise1_13() {
	//1.10 rewrite
	for(int n = 10;n>=0;--n){
		std::cout << n << std::endl;
	}
	//1.10 rewrite
	int sum = 0;
	for (int i = 50; i <= 100;i++){
		sum += i;
	}

	return sum;

}

static void exercise1_20() {
	//read transactions from cin and print to cout
	Sales_item item;
	while (std::cin >> item) {
		std::cout << item << std::endl;
	}
}


static void exercise1_21() {
	//print sum of 2 transactions
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn()) {
		std::cout << item1 + item2 << std::endl;
	}
}

static void exercise1_22() {
	//print sum of many transactions
	Sales_item item, sum;
	std::cin >> item;
	sum = item;
	std::cin >> item;
	while(item.isbn() == sum.isbn()) {
		sum += item;
		std::cin >> item;
	}
}


static void exercise1_23() {
	//print sum of many transactions
	Sales_item item, item1;
	int num_transactions =0;
	std::cin >> item1;
	while (std::cin >> item) {
		if (item1.isbn() == item.isbn()) {
			num_transactions++;
		}
		else {
			std::cout << item1 << num_transactions << std::endl;
			item1 = item;
			num_transactions = 0;
		}
	}
}