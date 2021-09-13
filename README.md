Alghoritem that find the shortest paths between to vertices in graph

for this algorihtem i implement by myself a LinkedList,Queue , BFS Algorithem and a graph with Adjacency Matrix


The program get the number of vertices in the graph (n) and two vertex s,t and edges.
the algorithem find the shortest path in graph between s & t.

Steps:
1.build the graph with the inputes (edges) as a Adjacency Matrix.

2.run bfs from vertex s.

3.remove from the graph all the edges that not in bfs tree.

4. invert the graph.

5.run bfs from vertex t.

6. remove all the edges that inaccessible from t.

7.invert the graph again.
