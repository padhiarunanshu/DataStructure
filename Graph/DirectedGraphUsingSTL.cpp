// source : https://www.techiedelight.com/graph-implementation-c-without-using-stl/

#include <iostream>
#include <vector>
using namespace std;

using Edge = vector<int> ;

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(const vector<Edge> &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the directed graph
		for (auto &edge: edges)
		{
			// insert at the end
			adjList[edge[0]].push_back(edge[1]);

			// Uncomment below line for undirected graph
			adjList[edge[1]].push_back(edge[0]);
		}
	}
};

// print adjacency list representation of graph
void printGraph(const Graph& graph, int N)
{
	for (int i = 0; i < N; i++)
	{
		// print current vertex number
		cout << i << " --> ";

		// print all neighboring vertices of vertex i
		for (int v : graph.adjList[i])
			cout << v << " ";
		cout << endl;
	}
}

// Graph Implementation using STL
int main()
{
	// vector of graph edges as per above diagram.
	vector<Edge> edges = {
		{0, 1}, {1, 2}, { 2, 0 }, { 2, 1 },{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// Number of nodes in the graph
	int N = 6;

	// construct graph
	Graph graph(edges, N);

	// print adjacency list representation of graph
	printGraph(graph, N);

	return 0;
}

/*
OUTPUT:
0 --> 1 
1 --> 2 
2 --> 0 1 
3 --> 2 
4 --> 5 
5 --> 4 
*/