/* 
    Name: Miguel Acero
    CSCI 33500
    Ioannis Stamos
    Assignment 5 part 2, Dijkstra's algorithm implementation

*/

#include "GraphFuncs.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <GRAPH_FILE> <STARTING_VERTEX>" << endl;
        return 0;
    }
    Graph g;
    const string graphFile(argv[1]);
    const int start = stoi(argv[2]);
    loadGraph(graphFile, g);
    g.Dijkstra(start);
}