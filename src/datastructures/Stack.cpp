#include "Stack.h"

#include <sstream>
#include <stdexcept>

DynArrayStack::DynArrayStack(int initialCapacity): capacity(initialCapacity), top(-1) {
	this->stack = new int[capacity] {0};
}

DynArrayStack::~DynArrayStack() {
	//release stack memory
	delete [] stack;
}

bool DynArrayStack::isEmptyStack() const {
	//empty if top is still -1
	return (top < 0);
}

bool DynArrayStack::isFullStack() const {
	return top+1 == capacity;
}

int DynArrayStack::getSize() const {
	return top + 1;
}

int DynArrayStack::getTop() const {
	if (isEmptyStack()) {
		throw std::underflow_error("No Items in Stack.");
	}
	return stack[top];
}

void DynArrayStack::push(int data) {
	//double stack first if needed
	if (isFullStack()) {
		_doubleStack();
	}
	++top;
	stack[top] = data;
}

int DynArrayStack::pop() {
	if (top < 0) {
		throw std::underflow_error("No Items to Pop Off Stack.");
	}
	return stack[top--];
}

void DynArrayStack::_doubleStack() {
	int *newStack = new int[2 * capacity] {0};
	for (int i = 0; i < capacity; i++) {
		newStack[i] = stack[i];
	}
	delete [] stack;
	stack = newStack;
	capacity = 2 * capacity;
}

string DynArrayStack::toString() const {
	//Traverse List and Format to String
	std::stringstream ss;
	ss << "(" << top << "," << capacity << ") ";
	ss << "[";
	for (int i = 0; i < capacity; i++) {
		ss << stack[i];
		if (i < capacity-1) ss << ", ";
	}
	ss << "]";
	return ss.str();
}

std::ostream & operator<<(std::ostream & os, const DynArrayStack &d) {
	// TODO: finish implementing input/output operators
	return os;
}