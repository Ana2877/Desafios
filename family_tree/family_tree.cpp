// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

int people_counter = 1;
unordered_map<std::string,int> hashmap;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
	// No. of vertices
	int V;

	// Pointer to an array containing adjacency lists
	list<int>* adj;

	// A function used by DFS
	void DFSUtil(int v, bool visited[]);

public:
	// Constructor
	Graph(int V);

	void addEdge(int v, int w);
	int NumberOfconnectedComponents();
};

// Function to return the number of
// connected components in an undirected graph
int Graph::NumberOfconnectedComponents(){

	// Mark all the vertices as not visited
	bool* visited = new bool[V];

	// To store the number of connected components
	int count = 0;
	for (int v = 0; v < V; v++)
		visited[v] = false;

	for (int v = 0; v < V; v++) {
		if (visited[v] == false) {
			DFSUtil(v, visited);
			count += 1;
		}
	}

	return count;
}

void Graph::DFSUtil(int v, bool visited[]){

	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

// Add an undirected edge
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int get_person_number(string name){
  	int person_number;

  	person_number = hashmap[name];
  
  	if(person_number == 0){
		hashmap[name] = people_counter;
		person_number = people_counter;
		people_counter++;
  	}

  	return person_number;
}

int main(){
	int vertices_number, arrests_number;
  	int number1, number2;
  	string name1, name2, ignore;
  
  	cin >> vertices_number >> arrests_number;

  	Graph g(vertices_number);

  	for(int i = 0; i < arrests_number; i++) {
    	cin >> name1 >> ignore >> name2;
    	number1 = get_person_number(name1);
    	number2 = get_person_number(name2);
    	g.addEdge(number1-1, number2-1);
  	}

  	cout << g.NumberOfconnectedComponents() << endl;

	return 0;
}
