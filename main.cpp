#include <stdio.h>
#include "Queue.h"
#include <iostream>
#include <fstream>
#include "Graph.h"
#include <chrono>
#include <iomanip>
#include "ShortestPathAlg.h"
using namespace std;

//the program include generic queue,generic linkedlist and a implement of graph class,
//the program should recieve n=num of vertex in graph , s=start vertex , t=end vertex and edges
//first we create an empty graph with n vertex and without edges and then recieve the edges
//finally we call to fucntion ShortestPathAlg::findShortestPath(G, s, t) that return a graph with shortest paths from s to t
int main() {
	
	int n, s, t;
	cin >> n;
	if (n < 1) {
		cout << "Wrong Input" << endl;
		exit(1);
	}
	cin >> s;
	cin >> t;
	if (s <= 0 || s>n ||t>n || t <= 0) {
		cout << "Wrong Input" << endl;
		exit(1);
	}

	Graph* G = new Graph();
	G->MakeEmptyGraph(n);
	G->ReadGraph();
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	Graph* H = ShortestPathAlg::findShortestPath(G, s, t);
	H->PrintGraph();
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "Time taken by function <findShortestPath> is : " << fixed
		<< time_taken << setprecision(9)<<" sec" << endl;;
	
	
	delete G;
	delete H;
}