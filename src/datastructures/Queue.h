#pragma once

#include <string>

using namespace std;

struct LLQueueNode {
	int data;
	LLQueueNode* next;
};

class LLQueue {

public:
	LLQueue();

	~LLQueue();

	string toString() const;

	int dequeue();
	void enqueue(int data);

	//Aux
	int getFront() const;
	int getRear() const;
	bool isEmptyQueue() const;

private:
	LLQueueNode* front;
	LLQueueNode* back;
};