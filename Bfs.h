#pragma once
#ifndef BFS_H
#define BFS_H
#include "Queue.h"
#include "Graph.h"
#include "LinkedList.h"

//class the implement Bfs algorithem the output is an array of integers
class Bfs {
private:
	int* d;
public:
	Bfs(int n) :d(new int[n]) {};
	~Bfs() { delete[] d; };
	void run(Graph* G, int s);//run the algorithem
	int* getDArray() { return d; }
};
#endif // !BFS_H
