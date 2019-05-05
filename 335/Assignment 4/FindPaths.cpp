// Kun Yu
// Assignnment 4
// Main Driver File for Part 2
// Reads in Graph files and creates a grpah and uses it to perform dijkstra's algorithm on given starting index

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Graph.h"

using namespace std;

void CreateGraph(const string &filename, Graph &g) {
	// Open file, check for errors
	ifstream graph_file;
	graph_file.open(filename);
	if (graph_file.fail())
	{
		cout << "Unable to open file\n";
		exit(1);
	}

	// Vertex connecting to and from
	int from, to;
	double weight;

	string graph_line;
	// First line includes number of vertices - Not used so skipped
	getline(graph_file, graph_line);
	while(getline(graph_file, graph_line)) {
		stringstream ss(graph_line);
		// Get vertex that all other vertices on line are connected to
		ss >> from;
		g.addVertex(from);

		// Parse through file adding connected vertex and its weight
		// Initializing vertices and edges
		while(ss >> to >> weight) {
			g.addVertex(to);
			g.addEdge(from, to, weight);
		}
	}
}

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Error. Usage: " << argv[0] << " <GRAPH_FILE> <STARTING_VERTEX>" << endl;
		return 0;
	}
	const string graph_filename(argv[1]);
	const int starting_index = stoi(argv[2]);
	Graph g;
	CreateGraph(graph_filename, g);
	g.performDijkstra(starting_index);
}