#pragma once


#include <iostream>
#include <string>
#include <cctype>

#include "Sales_item.h"

using namespace std;

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

static void exercise2_3() {
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;
	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;
	std::cout << i - i2 << std::endl;
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;
}

static void exercise2_23() {
	int p;
	int *pp;
	pp = &p;
	*pp = 5;
}

//String Exercises
static void exercise3_2() {
	string line;
	while (getline(cin, line)) {
		cout << line << endl;
	}

	string word;
	while (cin >> word) {
		cout << word << endl;
	}

}

static void exercise3_4() {
	string word1, word2;
	cin >> word1;
	cin >> word2;

	if (word1 == word2) {
		cout << "The Strings are Equal";
	}
	else {
		if (word1 > word2) {
			cout << "Word 1 is larger.";
		}
		else {
			cout << "Word 2 is larger.";
		}
	}

	int size1 = word1.length();
	int size2 = word2.length();
	if (size1 == size2) {
		cout << "The Strings are Equal Length";
	}
	else {
		if (size1 > size2) {
			cout << "Word 1 is longer.";
		}
		else {
			cout << "Word 2 is longer.";
		}
	}

}

static void exercise3_5() {

	string word;
	string cat = "";
	while (cin >> word) {
		cat += word;
	}
	cout << cat << endl;

}


static void exercise3_6() {

	string word = "word";
	for (auto &c: word) {
		c = 'X';
	}
}



string exercise3_10() {

	string sentence = "The cat's jumped over the hills!!";
	string output = "";
		for (auto &c: sentence) {
			if (ispunct(c)) {
				c = ' ';	//remove punctuation, replace with whitespace
			}
			else {
				output += c;	//add to output string only, whitespace will be removed
			}
		}
		return output;
}