#include<iostream>
#include <list>
using namespace std;

// This class represents a directed graph using adjacency list
// representation
class Graph{
	int V; // No. of vertices
	list<int> *adj; // Pointer to an array containing adjacency lists
	public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	bool isReachable(int s, int d);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d){
	if (s == d)
	return true;

	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// it will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty()){
		// Dequeue a vertex from queue and print it
		s = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i){
			// If this adjacent node is the destination node, then
			// return true
			if (*i == d)
				return true;

			// Else, continue to do BFS
			if (!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	
	// If BFS is complete without visiting d
	return false;
}

int main()
{	

  int number_of_tests;

  cin >> number_of_tests;

  for (int k = 0; k < number_of_tests; k++){
  
	Graph g(25);
  
    int previous_matrix_line[5], current_matrix_line[5];
  
    int previous_value, current_value;
  
    cin >> previous_value;
    previous_matrix_line[0] = previous_value;
    
    for (int i = 1; i < 5; ++i){
    	cin >> current_value;
    	previous_matrix_line[i] = current_value;
  
    	if(previous_value == 0 && current_value == 0) {
    		g.addEdge(i-1, i);
        	g.addEdge(i, i-1);
      }
  
      previous_value = current_value;
    }
  
    int vertice_value = 4;
    
    for (int j = 1; j < 5; j ++){
  
    	vertice_value ++;
    	cin >> previous_value;
    	current_matrix_line[0] = previous_value;
  
      	if(previous_matrix_line[0] == 0 && current_matrix_line[0] == 0){
        	g.addEdge(vertice_value-5, vertice_value);
        	g.addEdge(vertice_value, vertice_value-5);
      	}   
      
      	for (int i = 1; i < 5; ++i){
  
        	vertice_value ++;
        	cin >> current_value;
        	current_matrix_line[i] = current_value;
    
			if(previous_value == 0 && current_value == 0) {
				g.addEdge(vertice_value-1, vertice_value);
				g.addEdge(vertice_value, vertice_value-1);
			}
	
			if(previous_matrix_line[i] == 0 && current_matrix_line[i] == 0){
				g.addEdge(vertice_value-5, vertice_value);
				g.addEdge(vertice_value, vertice_value-5);
			}
		
			previous_value = current_value;
    	}
      
    	copy(begin(current_matrix_line), end(current_matrix_line), begin(previous_matrix_line));
    }
  
    if(g.isReachable(0, 24))
      	cout<< "COPS" << endl;
  	else
  		cout<< "ROBBERS" << endl;
  }
  
  return 0;
  
}