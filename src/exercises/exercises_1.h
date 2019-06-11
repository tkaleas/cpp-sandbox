#pragma once


#include <iostream>
#include <string>
#include <cctype>
#include <vector>

#include "Sales_item.h"
#include "Sales_data.h"

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

//bookstore application
static bool exercise1_6() {
	Sales_item total;
	if (cin >> total) {
		Sales_item trans;
		while (cin >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else {
		cerr << "No Data." << endl;
		return false;
	}
	return true;
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

void exercise3_14_15() {
	vector<int> list;
	vector<string> stringList;

	int cur;
	string curString;
	
	//3_14
	while (cin >> cur) {
		list.push_back(cur);
	}

	//3_15
	while (cin >> curString) {
		stringList.push_back(curString);
	}

}
template <typename T>
void printSizeContents(const std::vector<T>& a) {
	cout << a.size() << std::endl;
	for each (T obj in a)
	{
		cout << obj << ",";
	}
	cout << endl;
}

void exercise_3_16() {
	vector<int> v1;
	printSizeContents(v1);
	vector<int> v2(10); 

	printSizeContents(v2);
	vector<int> v3(10, 42);

	printSizeContents(v3);
	vector<int> v4{ 10 };

	printSizeContents(v4);
	vector<int> v5{ 10, 42 };

	printSizeContents(v5);
	vector<string> v6{ 10 };

	printSizeContents(v6);
	vector<string> v7{ 10, "hi" };

	printSizeContents(v7);

}

void exercise_3_20(){
	vector<int> v{ 10, 42, 25, 100, 87, 82 };
	for (int i = 0; i < v.size() / 2; i++) {
		int a = v[i];
		int b = v[v.size()-i-1];
		cout << a + b << endl;
	}
}

void exercise_3_31() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}

}

void exercise_3_35() {
	int a[10];
	int *p = a;
	for (int i = 0; i < 10; i++) {
		*(p+i) = i;
		cout << *(p + i) << endl;
	}

	
}

void exercise_4_21() {
	vector<int> n = { 0,1,2,3,4,5,6,7 };
	vector<int>::iterator iter;

	for (iter = n.begin(); iter != n.end(); ++iter) {
		*iter = ((*iter % 2) != 0) ? (*iter) * 2 : *iter;
	}

}

void exercise_5_14() {

	string inputWord, currentWord, maxWord;
	int curCount, maxCount;
	curCount = maxCount = 0;

	if (cin >> maxWord) {
		++maxCount;
	}

	while (cin >> inputWord) {
		if (currentWord == inputWord) {
			++curCount;
		}
		else {
			//check if We have a new max word
			if (curCount > maxCount) {
				maxWord = currentWord;
				maxCount = curCount;
			}
			//Reset Count
			currentWord = inputWord;
			curCount = 1;
		}
	}
	//Update Final Count after CIN
	if (curCount > maxCount) {
		maxWord = currentWord;
		maxCount = curCount;
	}

	//Report Max Word
	cout << "Max Word:" << maxWord << ", Max Count:" << maxCount << endl;

}

void exercise_5_23() {
	int i, j;
	cin >> i;
	cin >> j;
	try {
		if (j == 0)
			throw runtime_error("Cannot Divide By Zero");
		int d = i / j;
		cout << d << endl;
	}
	catch (runtime_error err) {
		cout << "Error" << err.what() << endl;
	}
}

int fact(int n) {
	// Does not handle overflow
	int t = n > 0 ? 1 : 0;
	for (int i = 1; i <= n; i++) {
		t *= i;
	}
	return t;
}

int sequencer() {
	static int s = -1;
	return ++s;
}

void reset(int &i) {
	i = 0;
}

int exercise_6_21(int i, int *p) {
	return i > *p ? i : *p;
}

void exercise_6_22(int *p1, int *p2) {
	//Value Swap
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	//Pointer Swap
	int *tempp = p1;
	p1 = p2;
	p2 = tempp;
}

//main with 2 arguements
int main_6_25(int argc, char **argv) {
	if (argc < 3) {
		return -1;
	}
	//No Error Checking: FYI
	char *option1 = argv[1];
	char *option2 = argv[2];
	string s1(option1);
	string s2(option2);
	string total = s1 + s2;
	cout << total << endl;
}

//main with many arguements
void main_6_26(int argc, char **argv) {

	//No Error Checking: FYI
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}
}

bool str_subrange(const string &str1, const string &str2) {
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size) i = 0; i != size; ++i) {
		if (str1[i] != str2[i])
			//return;
			return true;
	}
	return false;
}
//exercise_6_33(0,vector)
void exercise_6_33(int cpos, vector<int> v) {
	if (cpos > v.size()-1);
		return;
	cout << v[cpos]<< ",";
	exercise_6_33(cpos + 1, v);
}
