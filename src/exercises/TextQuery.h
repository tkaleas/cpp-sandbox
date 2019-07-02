#pragma once

#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <cctype>
#include <algorithm>
#include <numeric>

using namespace std;

class QueryResult;
class TextQuery {
public:
	// *<vector<string>
	shared_ptr<vector<string>> inputFile;
	// map<string, *<set<int>>>
	map<string, shared_ptr<set<int>>> queryMap;

	//initialize inputfile to heap
	TextQuery(ifstream &infile) : inputFile(new vector<string>)
	{
		string t;
		while (getline(infile, t)){
			inputFile->push_back(t);
			int ln = inputFile->size() - 1;//line number
			istringstream line(t);
			string word;
			while (line >> word) {
				shared_ptr<set<int>> pt = queryMap[word];
				if (!pt) {
					pt.reset(new set<int>);
				}
				pt->insert(ln);
			}
		}
	}

	QueryResult query(const string &s) const {
		auto pt = queryMap.find(s);
		QueryResult qr(pt->second, s, inputFile);
		return qr;
	}

};

class QueryResult {
	friend ostream& print(ostream &stream, QueryResult &qr);
public:
	string word;
	shared_ptr<set<int>> lineNumbers;
	shared_ptr<vector<string>> file;
	QueryResult(shared_ptr<set<int>> lineNum, string w, shared_ptr<vector<string>> f) :
		lineNumbers(lineNum),
		word(w),
		file(f) {}
};

ostream& print(ostream &stream, QueryResult &qr) {
	//print the word
	stream << "Element Is: " << qr.word << endl;
	//print the number of times total it occurs
	stream << "element occurs " << qr.lineNumbers->size() << "time" << endl;
	//for each element print line number, print line it occurs in
	for (auto itr = qr.lineNumbers->begin(); itr != qr.lineNumbers->end(); itr++) {
		string lineText = (*qr.file)[*itr];
		stream << "Line " << *itr + 1 << ": "<< lineText << endl;
	}
	
}

void runQueries(ifstream &infile)
{
	// infile is an ifstream that is the file we want to query 
	TextQuery tq(infile); 
	// store the file and build the query map 
	// iterate with the user: prompt for a word to find and print results
	while (true) { 
		cout << "enter word to look for, or q to quit: ";
		string s;
		// stop if we hit end-of-file on the input or if a 'q' is entered 
		if (!(cin >> s) || s == "q") break; 
		// run the query and print the results 
		print(cout, tq.query(s)) << endl;
	}
}