#include "Queue.h"

#include <sstream>

LLQueue::LLQueue() : front(nullptr), back(nullptr){

}

LLQueue::~LLQueue() {

}

string LLQueue::toString() const {
	//Traverse List and Format to String
	std::stringstream ss;
	LLQueueNode *c = front;
	if (!isEmptyQueue()) {
		ss << "(" << front->data << "," << back->data << ") ";
	}
	ss << "[";
	while (c != nullptr) {
		ss << c->data;
		if (c->next)
			ss << ", ";
		c = c->next;
	}
	ss << "]";
	return ss.str();
}

int LLQueue::dequeue() {
	//error state
	if (isEmptyQueue()) {
		throw  std::underflow_error("No Items to Dequeue");
	}

	int tempData = front->data;
	LLQueueNode* tempNode = front->next;

	//same node means only 1 element in the queue
	if (front == back) {
		back = nullptr;
	}

	//free memory
	delete front;
	
	//set new front queue node
	front = tempNode;
	return tempData;
}

void LLQueue::enqueue(int data) {
	LLQueueNode* newNode = new LLQueueNode();
	newNode->data = data;
	newNode->next = nullptr;

	if (isEmptyQueue()) {	//empty queue
		back = newNode;
		front = newNode;
	} else {
		back->next = newNode;
		back = newNode;
	}
}

//Aux
int LLQueue::getFront() const {
	return front->data;
}

int LLQueue::getRear() const {
	return back->data;
}

bool LLQueue::isEmptyQueue() const {
	if (front == nullptr)
		return true;
	return false;
}