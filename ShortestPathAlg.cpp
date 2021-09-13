#include "ShortestPathAlg.h"

Graph* ShortestPathAlg::findShortestPath(Graph * G, int s, int t)
{
	Bfs bfs1(G->getNumOfVertex());
	bfs1.run(G, s);
	clearEdges(G, bfs1.getDArray());
	Graph* GsT = getTGraph(G);
	Bfs bfs2(GsT->getNumOfVertex());
	bfs2.run(GsT, t);
	clearNotAccessibleEdges(GsT,bfs2.getDArray());
	Graph* H= getTGraph(GsT);
	delete GsT;
	return H;
	
}

Graph* ShortestPathAlg::getTGraph( Graph * G)//get graph and return his transpose graph
{
	Graph* T=new Graph(G->getNumOfVertex());
	for (int i = 1; i <= G->getNumOfVertex(); i++) {
		Node<Edge>* curr = G->GetAdjList(i).getHead();
		while (curr) {
			T->AddEdge(curr->data.vertex, i); //for each edge (u,v) add edge (v,u) to transpose graph
			curr = curr->next;
		}
	}
	return T;
}

void ShortestPathAlg::clearEdges(Graph* G, int * d){
	for (int i = 1; i <= G->getNumOfVertex(); i++) {
		Node<Edge>* curr = G->GetAdjList(i).getHead();
		Node<Edge>* temp;
		while (curr) {
			if (d[curr->data.vertex - 1] != d[i - 1]+1) {//d[v]!=d[u]+1
				temp = curr->next;
				G->RemoveEdge(i, curr->data.vertex);
				curr = temp;
			}
			else {
				curr = curr->next;
			}
		}
	}
}

void ShortestPathAlg::clearNotAccessibleEdges(Graph* G, int * d){
	for (int i = 1; i <= G->getNumOfVertex(); i++) {
		if (d[i-1] == -1) {
			G->GetAdjList(i).clear();
		}
	}
}
