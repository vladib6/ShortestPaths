#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//Generic Linkedlist
template <class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node(int data) :next(NULL), prev(NULL) {
		this->data = data;
	}
};

template <class T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
	
public:
	List() :head(NULL), tail(NULL){}
	~List() {
		Node<T>* curr = head;
		Node<T>* next;
		while (curr) {
			next = curr->next;
			delete(curr);
			curr = next;
		}
	}

	void addDataToEnd(int data) {addNodeToEnd(new Node<T>(data));}

	void addDataToStart(T data) {addNodeToStart(new Node<T>(data));}

	void addNodeToEnd(Node<T>* node) {
		if (this->head == NULL) {//if the list is empty
			this->head = node;
			this->tail = node;
		}
		else {
			this->tail->next = node;
			node->prev = tail;
			this->tail = node;
		}
	}

	void addNodeToStart(Node<T>* node) {
		if (this->head == NULL) {//if the list is empty
			this->head = node;
			this->tail = node;
		}
		else {
			node->next = this->head;
			this->head->prev = node;
			this->head = node;
		}
	}

	void removeFirst() {
		if (!isEmpty()) {
			Node<T>* temp = this->head;
			this->head = this->head->next;
			if (this->head) {
				this->head->prev = NULL;
			}
			else {
				tail = NULL;
			}
			delete(temp);
		}
	}
	bool isExist(T data) {//check if there is node with same data
		bool res = false;
		Node<T>* curr = head;
		while (curr) {
			if (curr->data == data) {
				res = true;
				break;
			}
			curr = curr->next;
		}
		return res;
	}

	void removeLast() {//remove the last node from list
		if (!isEmpty()) {
			Node<T>* temp = this->tail;
			this->tail = this->tail->prev;
			if (this->tail) {
				this->tail->next = NULL;
			}
			else {
				head = NULL;
			}
			delete(temp);
		}
	}
	void removeNode(Node<T>* node){
		if (!isEmpty()) {
			if (head == node) {
				Node<T>* temp = head;
				head = node->next;
				node->prev = NULL;
				delete temp;
			}
			else {
				Node<T>* curr = this->head;
				while (curr) {
					if (curr->data == node->data) {
						break;
					}
					curr = curr->next;
				}
				if (!curr) {//if we travel all the list
					std::cout << "The vertex not found" << std::endl;
				}
				else {
					if (!curr->next) {//the vertex is last
						this->tail = curr->prev;
						curr->prev->next = NULL;
						delete(curr);
					}
					else {
						curr->prev->next = curr->next;
						curr->next->prev = curr->prev;
						delete(curr);
					}
				}
			}
		}
	}
	void removeNode(int v) {
		if (head->data == v) {//if we want to delete the first node
			if (head->next) {//if there is more than 1 node in the list
				head->next->prev = NULL;
				Node<T>* temp = head;
				head = head->next;
				delete temp;
			}
			else {
				Node<T>* temp = head;
				head = NULL;
				tail = NULL;
				delete temp;
			}
		}
		else if (tail->data == v) {
			if (tail->prev) {//if there is more than 1 node in the list
				tail->prev->next = NULL;
				Node<T>* temp = tail;
				tail = tail->prev;
				delete temp;
			}
			else {
				Node<T>* temp = tail;
				head = NULL;
				tail = NULL;
				delete temp;
			}
		}
		else {
			Node<T>* curr = head;
			while (curr != NULL && !(curr->data == v)) {
				curr = curr->next;
			}
			if (curr) {
				Node<T>* temp = curr;
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				delete temp;
			}
			else {
				cout << "the node not found" << endl;
			}
		}
	}

	Node<T>* getFirst() { return head; }
	Node<T>* getLast() { return tail;}

	Node<T>* getHead() { return head; }
	Node<T>* getTail() { return tail; }

	void clear() {
		Node<T>* curr = head;
		Node<T>* next;
		while (curr) {
			next = curr->next;
			delete(curr);
			curr = next;
		}
		head = NULL;
		tail = NULL;
	}
	bool isEmpty() {return head==NULL? true :false; }
	void printList() {
		Node<T>* curr = head;
		while (curr) {
			cout << curr->data << endl;
			curr = curr->next;
		}
	}
	bool IsAdjancent(int v) {
		bool res = false;
		Node<T>* curr = head;
		while (curr) {
			if (curr->data == v) {
				res = true;
				break;
			}
		}
		return res;
	}
};


#endif // !LINKEDLIST