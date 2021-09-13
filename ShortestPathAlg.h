#pragma once
#ifndef SHORTESTPATHALG_H
#include "Graph.h"
#include "Bfs.h"

class ShortestPathAlg {
public:
	 static Graph* findShortestPath(Graph* G,int s ,int t);
	 static Graph* getTGraph( Graph* G);// create transpose graph
	 static void clearEdges(Graph* G,int* d);//remove all the edges that not maintain d[v]=d[u]+1
	 static void clearNotAccessibleEdges(Graph* G, int* d);//clear all the edges that not accessible from s,all the edges that their distance from starting vertex is -1

};
#endif // !SHORTESTPATHALG_H
