#include "Graph.h"

void Graph::MakeEmptyGraph(const int n)
{
	adjacencyList = new List<Edge>[n]();
	numOfVertex = n;
}

bool Graph::IsAdjancent(int u, int v){return adjacencyList[u-1].IsAdjancent(v);}

List<Edge>& Graph::GetAdjList(const int u)const{return adjacencyList[u-1];}

void Graph::AddEdge(int u, int v){adjacencyList[u-1].addDataToEnd(v);}

void Graph::RemoveEdge(int u, int v){adjacencyList[u-1].removeNode(v);}

void Graph::ReadGraph(){
	int from, to;
	cin >> from;
	cin >> to;
	while (cin>>from && cin>>to) {
		if (from > numOfVertex || from<1 || to>numOfVertex || to < 1) {
			cout << "Wrong Input" << endl;
			
			exit(1);
		}
		AddEdge(from, to);
	}
	if (!to) {//if the last input edge include only "from" so to will be equal to 0 and this is a wrong input
		cout << "Wrong Input" << endl;
		exit(1);
	}
}

Edge* Graph::makeNewEdge(const int v)
{
	Edge* e=new Edge();
	e->vertex = v;
	return e;
}

void Graph::PrintGraph(){
	for (int i = 1; i <= numOfVertex; i++) {
		Node<Edge>* curr = adjacencyList[i - 1].getHead();
		if (curr) {
			while (curr) {
				cout << "(" << i << "," << curr->data << ") ";
				curr = curr->next;
			}
			cout << endl;
		}
		
	}
}

int Graph::IsEmpty(){return numOfVertex == 0 ? true : false;}
