#pragma once

#include <string>
#include <iostream>

using namespace std;

// Linked List Classes for Integers
struct ListNode {
	ListNode() : data(0), next(nullptr) {}
	ListNode(int d) : data(d), next(nullptr) {}
	
	~ListNode() {}

	int data;
	ListNode *next;
};

class SinglyLinkedList {

public:
	friend std::ostream & operator<<(std::ostream & os, const SinglyLinkedList &ll);

public:
	SinglyLinkedList();
	SinglyLinkedList(int startValue);

	~SinglyLinkedList();

	string toString() const;

	void insertIntoList(size_t position, int value); //if runs past position insert at end of list
	void deleteFromList(size_t  position);
	void popFromList(size_t  position);
	int getValue(size_t position);
	int getFirst();
	void clearList();

private:
	ListNode* head;

};

std::ostream & operator<<(std::ostream & os, const SinglyLinkedList &ll);