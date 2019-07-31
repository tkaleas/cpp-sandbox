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
	while (c != nullptr) {
		ss << c->data;
		if(c->next)
			ss << ", ";
		c = c->next;
	}
	ss << "]";
	return ss.str();
}

void SinglyLinkedList::insertIntoList(size_t position, int value) 
{
	int k = 0;
	ListNode* curr = this->head;
	ListNode* prev = curr;

	//Insert at beginning if no other items or inserting at position 0
	if (curr == nullptr || position == 0) {
		ListNode* temp = curr;
		this->head = new ListNode(value);
		this->head->next = temp;
		return;
	}

	while (k < position && curr != nullptr) {
		k++;
		prev = curr;
		curr = curr->next;
	}

	//Insert At Position
	if (curr != nullptr) {
		ListNode* newNode = new ListNode(value);
		ListNode* temp = curr;
		prev->next = newNode;
		newNode->next = temp;
	}

	//Insert at End
	else {
		ListNode* newNode = new ListNode(value);
		prev->next = newNode;
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