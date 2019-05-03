// Kun Yu
// Assignnment 4
// Main Driver File for Part 1
// Reads in Graph files and creates a grpah and uses it to query through query file

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

void QueryGraph(const string &filename, Graph &g) {
	// Open file, check for errors
	ifstream query_file;
	query_file.open(filename);
	if (query_file.fail())
	{
		cout << "Unable to open file\n";
		exit(1);
	}

	// Vertex connecting to and from
	int from, to;

	while(query_file >> from >> to) {
		if (g.isAdjacent(from, to)) {
			cout << from << " " << to << ": Connected, weight of edge is " << g.getWeight(from, to) << endl;
		}
		else {
			cout << from << " " << to << ": Not connected" << endl;
		}
	}
}

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Error. Usage: " << argv[0] << " <graphfilename> <queryfilename>" << endl;
		return 0;
	}
	const string graph_filename(argv[1]);
	const string query_filename(argv[2]);
	Graph g;
	CreateGraph(graph_filename, g);
	QueryGraph(query_filename, g);
	// g.printGraph();
}