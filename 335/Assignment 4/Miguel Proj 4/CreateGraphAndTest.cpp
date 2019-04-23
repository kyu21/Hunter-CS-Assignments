#include <iostream>
#include "GraphFuncs.h"

using namespace std;

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << "<GRAPH_FILE> <QUERY_FILE>" << endl;
		return 0;
	}
	const string graphFile(argv[1]);
	const string queryFile(argv[2]);
	Graph g;
	loadGraph(graphFile, g);
	// int a = 1, b = 2;
	// cout << g.exists(1);
	// cout << g.getWeight(a, b) << endl;
	queryGraph(queryFile, g);
	return 0;
}
