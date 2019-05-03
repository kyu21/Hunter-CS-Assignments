// Kun Yu
// Assingment 4
// Graph Implementation

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <list>

using namespace std;

class Graph {
	public:
		// Big Five
		Graph() = default;
		~Graph() = default;	
		Graph &operator=(const Graph &rhs) = default;
		Graph(Graph &&rhs) = default;
		Graph &operator=(Graph &&rhs) = default;

		// creating graph
		void addVertex(const int &val);
		void addEdge(const int &from, const int &to, const double &weight);

		// querying graph
		double getWeight(const int &from, const int &to) const;
		bool isVertexExist(const int &v) const;
		bool isAdjacent(const int &v1, const int &v2) const;

		// helper functions
		void printGraph() const;

	private:
		struct vertex {
			int value;
			double weight;
			unordered_map<int, double> adj_list;
			vertex(int num): value(num) {};
		};
		map<const int, vertex> vertices_;
};

#endif //GRAPH_H