#pragma once


#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>

#include "Sales_item.h"
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"

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

//bookstore application : revised
static bool exercise7__1_4() {
	Sales_data total_books;
//	float price;
	// Example Input: 0 - 201 - 70353 - X 4 22.99
//	if (cin >> total_books.bookNo >> total_books.units_sold >> price) {
//		total_books.revenue = total_books.units_sold * price;
	if (read(cin, total_books)) {
		Sales_data trans;
//		while (cin >> trans.bookNo >> trans.units_sold >> price) {
//			trans.revenue = trans.units_sold * price;
		while (read(cin,trans)) {
			if (total_books.isbn() == trans.isbn()) {
				//total_books.combine(trans);
				total_books = add(total_books, trans);
			} else {
				//New Book -> Empty Transaction List
				//cout << total_books.bookNo << " " << total_books.revenue << " " << total_books.units_sold << endl;
				print(cout, total_books);
				total_books = trans;
			}
		}
		//Final Book Transaction List
		//cout << total_books.bookNo << " " << total_books.revenue << " " << total_books.units_sold << endl;
		print(cout, total_books);
		cout << endl;
	}
	else {
		cerr << "No Data." << endl;
		return false;
	}
	return true;
}

//bookstore application : revised
static bool exercise_7_13() {
	Sales_data total_books(cin);
	if (cin) {								//still has input
		Sales_data trans;
		while (cin) {
			if (total_books.isbn() == trans.isbn()) {
				//total_books.combine(trans);
				total_books = add(total_books, trans);
			}
			else {
				//New Book -> Empty Transaction List

				print(cout, total_books);
				total_books = trans;
			}
		}
		//Final Book Transaction List
		print(cout, total_books);
		cout << endl;
	}
	else {
		cerr << "No Data." << endl;
		return false;
	}
	return true;
}

void exercise_7_27() {
	//Testing Screen Code
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);
	cout << endl;
}

//Exercise 7.31
class Y;
class X {
	Y *y;
};

class Y {
	X y;
};

istream& writeToConsole(istream &is) {
	string input;
	while (is >> input)
		cout << input;
	is.clear();
	return is;
}

void exercise_8_2() {
	writeToConsole(cin);
}

void exercise_9_14() {

	std::list<char*> l1 = {"Hi", "Hello", "Guten Tag", "Jezebel" };
	auto &iBegin = l1.begin();
	auto &iEnd = l1.end();
	vector<string> l2;
	
	l2.assign(iBegin, iEnd);
}

void exercise_9_18() {
	string word;
	//deque<string> d;
	list<string> d;		//Literally the only change needed to convert to a list
	while (cin >> word) {
		d.push_back(word);
	}

	for (auto &iter = d.cbegin(); iter != d.cend(); iter++) {
		cout << *iter << endl;
	}

}

void exercise_9_20() {
	list<int> intList = { 1,2,3,4,5,6,7,8,22,80,53,75 };
	deque<int> even;
	deque<int> odd;

	for (auto iter = intList.begin(); iter != intList.end(); ++iter) {
		int n = *iter;
		if (n % 2 == 0) {
			even.push_back(n);
		}
		else {
			odd.push_back(n);
		}
	}

}

//iterators, insert erase
string exercise_9_43(string s, string oldVal, string newVal) {
	string sNew = s;
	auto iter = sNew.begin();
	while (iter != sNew.end() - (oldVal.length()-1)) {
		string sub(iter,iter + oldVal.length());
		if (sub == oldVal) {
			iter = sNew.erase(iter, iter + oldVal.length());
			iter = sNew.insert(iter, newVal.begin(), newVal.end());
			//s.replace(iter, iter + oldVal.length(), newVal);
		}
		++iter;
	}
	return sNew;
}

string exercise_9_44(string s, string oldVal, string newVal) {
	for (int i = 0; i < s.length(); ++i) {
		string sub = s.substr(i,oldVal.length());
		if (sub == oldVal) {
			s.replace(i,oldVal.length(), newVal);
		}
	} 
	return s;
}

string exercise_9_45(string name, string prefix, string suffix) {
	name.insert(0, prefix + " ");
	name.append(" " + suffix);
	return name;
}

void countNumbers(int num) {

	//Exercise 10_1 10_2
	//vector<int> testNumbers = { 1,2,5,6,1,4,4,4,5,5,5,6,1,5,1,3,7,8 };
	list<int> testNumbers = { 1,2,5,6,1,4,4,4,5,5,5,6,1,5,1,3,7,8 };
	cout << count(testNumbers.begin(), testNumbers.end(), num) << endl;

}

void accumulateNum() {

	//Exercise 10_1 10_2
	vector<int> testNumbers = { 1,2,5,6,1,4,4,4,5,5,5,6,1,5,1,3,7,8 };
	int sum = accumulate(testNumbers.cbegin(), testNumbers.cend(), 0);
	cout << sum << endl;
}

void elimDups(vector<string> &words) {
	for (auto iter = words.begin(); iter != words.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;

	sort(words.begin(), words.end());
	auto end_new = unique(words.begin(), words.end());
	words.erase(end_new, words.end());

	for (auto iter = words.begin(); iter != words.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;
}

bool compareIsbns(const Sales_data &sd1, const Sales_data &sd2) {
	return sd1.isbn() < sd2.isbn();
}

void exerciseIsbns(vector<Sales_data> &data) {
	sort(data.begin(), data.end(), compareIsbns);
}

bool isLong(string s) {
	return s.length() >= 5;
}

void partitionWords(vector<string> &words) {
	for (auto iter = words.begin(); iter != words.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;

	partition(words.begin(), words.end(), isLong);

	for (auto iter = words.begin(); iter != words.end(); ++iter) {
		cout << *iter << ",";
	}
	cout << endl;
}

//Lambda Exercises
auto sumLambda = [](const int &a, const int &b) {return a + b; };

void captureLambdaTest() {
	int test = 5;
	auto captureLambda = [test](const int &b) {return test + b; };
}

void exerciseIsbnsLambda(vector<Sales_data> &data) {
	sort(data.begin(), data.end(), [] (const Sales_data &a, const Sales_data &b) { return a.isbn() < b.isbn(); });
}

//Dynamic Memory Allocation Exercises
void exercise_12_6_reader(vector<int> *dyn_ints) {
	int temp;
	while (cin >> temp) {
		dyn_ints->push_back(temp);
	}
}

void exercise_12_6_printer(vector<int> *dyn_ints) {
	for (int i = 0; i < dyn_ints->size(); i++) {
		cout << (*dyn_ints)[i] << "," ;
	}
	cout << endl;
}

void exercise_12_6() {
	vector<int> *dyn_ints = new vector<int>();
	exercise_12_6_reader(dyn_ints);
	exercise_12_6_printer(dyn_ints);
	delete dyn_ints;
}


void exercise_12_6_reader_SHARED(shared_ptr<vector<int>> dyn) {
	int temp;
	while (cin >> temp) {
		dyn->push_back(temp);
	}
}

void exercise_12_6_printer_SHARED(shared_ptr<vector<int>> dyn) {
	for (int i = 0; i < dyn->size(); i++) {
		cout << (*dyn)[i] << ",";
	}
	cout << endl;
}

void exercise_12_6_SHARED() {
	auto dyn_ints = make_shared<vector<int>>();
	exercise_12_6_reader_SHARED(dyn_ints);
	exercise_12_6_printer_SHARED(dyn_ints);
}