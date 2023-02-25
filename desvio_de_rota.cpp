// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>
#include <vector>

// Number of vertices in the graph
int number_of_v;

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[], int service_number, bool canUpdate[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < number_of_v; v++){
      
      if(sptSet[v] == false) {
        if (dist[v] <= min) {
          min = dist[v], min_index = v;
        }
      }
    }

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int dest)
{
	//cout << "Vertex \t Distance from Source" << endl;
	//for (int i = 0; i < number_of_v; i++)
	 //cout << i << " \t\t\t\t" << dist[i] << endl;
  cout << dist[dest] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(vector<vector<int>>& graph, int src, int service_number)
{
	int dist[number_of_v]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[number_of_v]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

  bool canUpdate[number_of_v];

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < number_of_v; i++)
		dist[i] = INT_MAX, sptSet[i] = false, canUpdate[i] = true;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < number_of_v - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet, service_number, canUpdate);

    //cout << "can update " << canUpdate[u] << endl;

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.

    int service_aux = service_number;
    
		for (int v = 0; v < number_of_v; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && u < service_aux && v < service_aux && dist[u] + graph[u][v] < dist[v]) {
        if ( v == (u + 1) || u == (v + 1))
          dist[v] = dist[u] + graph[u][v];
      }
      
			else if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
        }
	}

	// print the constructed distance array
	printSolution(dist, service_number - 1);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
  int number_of_arrests, number_of_vertices, v, u, weight, service_number, city;

  cin >> number_of_vertices >> number_of_arrests >> service_number >> city;

  while (!(number_of_vertices == 0 && number_of_arrests == 0 && service_number == 0 && city == 0)){

    number_of_v = number_of_vertices;
  
    vector<vector<int>> my_graph( number_of_vertices , vector<int> (number_of_vertices));
  
    for (int i = 0; i < number_of_arrests; i ++){
      cin >> v >> u >> weight;
  
      my_graph[v][u] = weight;
      my_graph[u][v] = weight;
    }
  
    dijkstra(my_graph, city, service_number);

    cin >> number_of_vertices >> number_of_arrests >> service_number >> city;
  }
  
	return 0;
}
