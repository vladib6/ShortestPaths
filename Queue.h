#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
//Generic Queue
template <class T>
class Queue {
private:
	List<T>* queue;

public:
	Queue() :queue(new List<T>()) {}
	~Queue() { delete(queue); }
	void enqueue(T data) { queue->addDataToStart(data); }

	T dequeue() {
		T res=queue->getLast()->data;
		queue->removeLast();
		return res;
	}
	bool isEmpty() { return queue->isEmpty(); }

};





#endif // !QUEUE_H

