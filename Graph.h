#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"

struct Edge {
	int vertex;
	bool used=false;

	friend ostream& operator<<(ostream& os, const Edge e) {
		cout <<e.vertex ;
		return os;
	}

	bool operator== (const int& v) {
		return vertex == v;
	}
	bool operator== (const Edge& e) {
		return vertex == e.vertex;
	}
	void operator= (const Edge& e) {
		this->vertex = e.vertex;
		this->used = e.used;
	}
	void operator= (const int& v) {
		this->vertex = v;
	}
};

class Graph {
private:
	List<Edge>* adjacencyList;
	int numOfVertex;
public:
	Graph() :adjacencyList(NULL) { numOfVertex = 0; }
	Graph(int n) { MakeEmptyGraph(n); }
	~Graph() { delete[] adjacencyList; }
	void MakeEmptyGraph(int n);
	bool IsAdjancent(int u, int v);
	List<Edge>& GetAdjList(int u)const;
	void AddEdge(int u, int v);
	void RemoveEdge(int u, int v);
	void ReadGraph();
	Edge* makeNewEdge(int v);
	void PrintGraph();
	int IsEmpty();
	const int& getNumOfVertex() const { return numOfVertex; }
};
#endif // !GRAPH_H

