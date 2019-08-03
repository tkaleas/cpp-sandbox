#pragma once

#include <string>
#include <iostream>

using namespace std;

// Linked List Stack Implementation
struct StackNode {
	StackNode() : data(0), next(nullptr) {}
	StackNode(int d) : data(d), next(nullptr) {}
	
	~StackNode() {}

	int data;
	StackNode *next;
};

class DynArrayStack {

public:
	friend std::ostream & operator<<(std::ostream & os, const DynArrayStack &ll);

public:
	DynArrayStack(int capacity);

	~DynArrayStack();

	string toString() const;

	void push(int data);
	int pop();

//Aux
	int getTop() const;
	int getSize() const;
	bool isEmptyStack() const;
	bool isFullStack() const ;

	static void InsertAtBottom(DynArrayStack &S, int data) {
		//base case: empty stack
		if (S.isEmptyStack()) {
			S.push(data);
			return;
		}
		int temp = S.pop();
		InsertAtBottom(S, data);
		S.push(temp);
	}

	//Reverse Stack using push/pop
	static void ReverseStack(DynArrayStack &S) {
		//recursion base case: empty stack
		if (S.isEmptyStack()) {
			return;
		}
		//pop
		int temp = S.pop();
		//reverse stack
		ReverseStack(S);
		//insert at bottom
		InsertAtBottom(S, temp);
	}

private:
	int top;
	std::size_t capacity;
	int *stack;
	void _doubleStack();
};
     
std::ostream & operator<<(std::ostream & os, const DynArrayStack &d);