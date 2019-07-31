#include "LinkedList.h"

#include <sstream>

SinglyLinkedList::SinglyLinkedList() :
					head(nullptr)
{

}

SinglyLinkedList::SinglyLinkedList(int startValue):
					head(new ListNode(startValue))
{

}

SinglyLinkedList::~SinglyLinkedList() 
{
	this->clearList();
	delete head;
}

void SinglyLinkedList::clearList() {

}

int SinglyLinkedList::getFirst() {
	if (head != nullptr) {
		return head->data;
	}
}

int SinglyLinkedList::getValue(size_t position) {
	int k = 0;
	ListNode* curr = head;

	while (k < position && curr->next != nullptr) {
		k++;
		curr = curr->next;
	};

	return curr->data;
}

string SinglyLinkedList::toString() const{
	//Traverse List and Format to String
	std::stringstream ss;
	ListNode *c = head;
	ss << "[";
	while (c->next != nullptr) {
		ss << c->data;
		if(c->next)
			ss << ", ";
	}
	ss << "]";
	return ss.str();
}

void SinglyLinkedList::insertIntoList(size_t position, int value) 
{
	int k = 0;
	ListNode* curr = head;

	//Insert at beginning if no other items or inserting at position 0
	if (curr == nullptr || position == 0) {
		this->head = new ListNode(value);
		this->head->next = nullptr;
		return;
	}

	while (k < position && curr->next != nullptr) {
		k++;
		curr = curr->next;
	}

	//Insert At Position
	if (curr->next) {
		ListNode* newNode = new ListNode(value);
		ListNode* temp = curr->next;
		curr->next = newNode;
		newNode->next = temp;
	}
	//Insert at End
	else {
		ListNode* newNode = new ListNode(value);
		curr->next = newNode;
	}
}

void SinglyLinkedList::deleteFromList(size_t  position) {

}

void SinglyLinkedList::popFromList(size_t  position) {

}

std::ostream & operator<<(std::ostream & os, const SinglyLinkedList &ll) {
	os << ll.toString();
	return os;
}