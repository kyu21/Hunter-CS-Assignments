/*

    name: Miguel Acero
    Assignment 5
	CSCI 33500
	Ioannis Stamos

	Topological Sort,
	sorted the vertices in the graph in topological order.
*/
#include <iostream>
#include "GraphFuncs.h"

using namespace std;

//Topologically sorts an input Graph
int main(int argc, char const *argv[]) {
	if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file_for_graph>" << endl;
	}
	const string file_name(argv[1]);

	Graph g;
	loadGraph(file_name, g);
	g.topSort();
	return 0;
}