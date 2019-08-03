#include "catch.hpp"

#include <sstream>
#include <iostream>

//Some Trivial Tests to make sure Catch is working correctly. 
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

TEST_CASE("Testing Singly Linked Construction") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}

TEST_CASE("Testing Singly LinkedList toString()") {
	SinglyLinkedList list(0);
	REQUIRE(list.toString() == "[0]");
	list.insertIntoList(0, 1);
	REQUIRE(list.toString() == "[1, 0]");
}

TEST_CASE("Testing Singly Linked InsertIntoList") {
	SinglyLinkedList list(0);
	//Test Insert Front
	list.insertIntoList(0, 1);
	list.insertIntoList(0, 2);
	list.insertIntoList(0, 3);
	REQUIRE(list.toString() == "[3, 2, 1, 0]");
	//Test Insert Middle
	list.insertIntoList(2, 20);
	REQUIRE(list.toString() == "[3, 2, 20, 1, 0]");
	//Test Insert End
	list.insertIntoList(100, 300);
	REQUIRE(list.toString() == "[3, 2, 20, 1, 0, 300]");
}

TEST_CASE("Testing Singly Linked GetFirst") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
}

TEST_CASE("Testing Singly Linked GetValue") {
	SinglyLinkedList list(20);
	REQUIRE(list.getValue(0) == 20);
	list.insertIntoList(1, 10);
	REQUIRE(list.getValue(1) == 10);
}

TEST_CASE("Testing Singly Linked deleteFromList") {
	SinglyLinkedList list(0);
	list.insertIntoList(1, 1);
	list.insertIntoList(2, 2);
	list.insertIntoList(3, 3);
	list.insertIntoList(4, 4);
	list.insertIntoList(5, 5);

	//Test Delete Front
	list.deleteFromList(0);
	REQUIRE(list.toString() == "[1, 2, 3, 4, 5]");
	//Test Delete Middle
	list.deleteFromList(2);
	REQUIRE(list.toString() == "[1, 2, 4, 5]");
	//Test Delete End (Exact End)
	list.deleteFromList(3);
	REQUIRE(list.toString() == "[1, 2, 4]");
	//Test Delete End (Far)
	list.deleteFromList(100);
	REQUIRE(list.toString() == "[1, 2]");
	list.deleteFromList(0);
	list.deleteFromList(0);
	REQUIRE(list.toString() == "[]");
	list.deleteFromList(0);
	REQUIRE(list.toString() == "[]");
}

TEST_CASE("Testing Singly Linked popFromList") {
	//
}

TEST_CASE("Testing Linked List Input Operator (<<)") {
	//
}


TEST_CASE("Test Dynamic Array Stack - Push ") {
	DynArrayStack stack(5);
	stack.push(5);
	stack.push(10);
	stack.push(10);
	REQUIRE(stack.toString() == "(2,5) [5, 10, 10, 0, 0]");
}

TEST_CASE("Test Dynamic Array Stack - Top ") {
	DynArrayStack stack(5);
	stack.push(5);
	stack.push(10);
	REQUIRE(stack.getTop() == 10);
}


TEST_CASE("Test Dynamic Array Stack - Size ") {
	DynArrayStack stack(5);
	stack.push(5);
	stack.push(10);
	stack.push(10);
	REQUIRE(stack.getSize() == 3);
}

TEST_CASE("Test Dynamic Array Stack - Pop") {
	DynArrayStack stack(5);
	stack.push(5);
	stack.push(10);
	stack.push(15);
	REQUIRE(stack.pop() == 15);
	REQUIRE(stack.pop() == 10);
	REQUIRE(stack.pop() == 5);
}

TEST_CASE("Test Dynamic Array Stack - Pop(Underflow)") {
	DynArrayStack stack(5);
	stack.push(5);
	stack.push(10);
	stack.push(10);
	stack.pop();
	stack.pop();
	stack.pop();
	REQUIRE_THROWS(stack.pop());
	REQUIRE_THROWS(stack.getTop());
}


TEST_CASE("Test Dynamic Array Stack - Stack Double ") {
	DynArrayStack stack(3);
	stack.push(5);
	stack.push(10);
	stack.push(10);
	stack.push(1);
	REQUIRE(stack.toString() == "(3,6) [5, 10, 10, 1, 0, 0]");
}


TEST_CASE("Test Dynamic Array Stack - Reverse Stack ") {
	DynArrayStack stack(3);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	DynArrayStack::ReverseStack(stack);
	REQUIRE(stack.toString() == "(2,3) [3, 2, 1]");
}


TEST_CASE("Test Linked List Queue - Enqueue") {
	LLQueue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	cout << q.toString() << endl;
	//REQUIRE(q.toString() == "(2,3) [3, 2, 1]");
}

TEST_CASE("Test Linked List Queue - Dequeue") {
	LLQueue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	REQUIRE(q.dequeue() == 1);
	REQUIRE(q.dequeue() == 2);
	REQUIRE(q.dequeue() == 3);
	REQUIRE(q.dequeue() == 4);
	REQUIRE(q.dequeue() == 5);
	REQUIRE_THROWS_AS(q.dequeue(), std::underflow_error);
}