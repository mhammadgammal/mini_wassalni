// C++ program for Dijkstra's single source shortest path
// algorithm.The program is for adjacency matrix
// representation of the graph.
#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 7

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++)
		if (sptSet[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;
	return min_index;
}

// Function to print shortest path from source to j using
// parent array
void printPath(int parent[], int j){
//cout << "*-*-*-*-" << parent[j]<<"**-*-*-*-*-*";
	// Base Case : If j is source
	if (parent[j] != -1)
	{
		printPath(parent, parent[j]);
		cout << j << " ";
	}
}

// A utility function to print the constructed distance
// array
int printSolution(int dist[],  int parent[])
{
	int src = 0;
	cout << "Vertex\t Distance\tPath";
	for (int i = 1; i < V; i++) {
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i],
			src);
		printPath(parent, i);
	}
	return 0;
}

//
void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V] = { false };
	int parent[V] = { -1 };
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]&& dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, parent);
}

// Driver Code
int main()
{
	// Let us create the example graph discussed above
	int graph[V][V] = { {0,5,3,0,0,0,0},{0,0,2,0,3,0,1},{0,0,0,7,7,0,0},{2,0,0,0,0,6,0},{0,0,0,2,0,1,0},{0,0,0,0,0,0,0},
								{0,0,0,0,1,0,0} };
	dijkstra(graph, 0);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
