#include "Graph.h"

void Graph::addVertex(const int &val) {
	vertices_.insert(pair<int, vertex>(val, vertex(val)));
}

void Graph::addEdge(const int &from, const int &to, const double &weight) {
	auto vertex = vertices_.find(from);
	vertex->second.adj_list.insert(pair<int, double>(to, weight));
}

double Graph::getWeight(const int &from, const int &to) const{
	// Check if the two vertex are adjancet to each other
	if (!(isAdjacent(from, to))) {
		return -1;
	}
	auto vertex = vertices_.find(from);
	return vertex->second.adj_list.find(to)->second;
}

bool Graph::isVertexExist(const int &v) const {
	// If the search through vertices_ doesn't find anything, iterator to last element
	// True if found element
	// False if element is end
	return vertices_.find(v) != vertices_.end();
}

bool Graph::isAdjacent(const int &v1, const int &v2) const {
	// Check if verteices exist
	if (!(isVertexExist(v1) && isVertexExist(v2))) {
		return false;
	}
	auto vertex = vertices_.find(v1);
	// Returns if the 2nd vertex is found in 1st vertex's adj list
	return vertex->second.adj_list.find(v2) != vertex->second.adj_list.end();
}

void Graph::printGraph() const {
	for (auto v : vertices_) {
		cout << v.first << ":" << endl;
		for (auto v2 : v.second.adj_list) {
			cout << v2.first << " " << v2.second << endl;
		}
		cout << endl;
	}
}