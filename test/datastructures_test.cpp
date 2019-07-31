#include "catch.hpp"

#include <sstream>
#include <iostream>

//Some Trivial Tests to make sure Catch is working correctly. 

#include "LinkedList.h"

TEST_CASE("Testing Singly Linked Construction") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}

TEST_CASE("Testing Singly Linked GetValue") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}

TEST_CASE("Testing Singly Linked String") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}

TEST_CASE("Testing Singly Linked insertIntoList") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}

TEST_CASE("Testing Singly Linked deleteFromList") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}

TEST_CASE("Testing Singly Linked popFromList") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}

TEST_CASE("Testing Linked List Input Operator (<<)") {
	SinglyLinkedList list(0);
	int val = list.getFirst();
	REQUIRE(val == 0);
	SinglyLinkedList list2(100);
	val = list2.getFirst();
	REQUIRE(val == 100);
}