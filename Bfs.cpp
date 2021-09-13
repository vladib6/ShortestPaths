#include "Bfs.h"

void Bfs::run(Graph* G,int s){//get the graph and origin vertex  and run Bfs Algo
	Queue<int> q;
	for (int i = 0; i < G->getNumOfVertex(); i++) {
		d[i] = -1;
	}
	d[s-1] = 0;
	q.enqueue(s);

	while (!q.isEmpty()) {
		int u = q.dequeue();
		Node<Edge>* curr = G->GetAdjList(u).getHead();
		while (curr) {
			if (d[curr->data.vertex - 1] == -1) {
				d[curr->data.vertex - 1] = d[u - 1] + 1;
				q.enqueue(curr->data.vertex);
			}
			curr = curr->next;
		}
	}
}
