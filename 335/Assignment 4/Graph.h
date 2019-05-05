// Kun Yu
// Assingment 4
// Graph Implementation

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
#include <limits>
#include <cstdlib>
#include <ctime>

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
		double getDistance(const int &v);
		int getOutdegree(const int &v) const;

		// dijkstra
		void performDijkstra(const int &start);
		void printPath(const int &v);

		// Random Graph
		void makeAndTestRandomGraph(const int &numNodes);

		// helper functions
		void printGraph() const;

	private:
		struct vertex {
			int value;
			double distance;
			unordered_map<int, double> adj_list;

			bool known; //dijkstra
			vertex* next; //dijkstra

			int outdegree = 0; //Part 3

			vertex() : next(nullptr) {}
			vertex(int num) : value(num), next(nullptr) {}
		};
		map<const int, vertex> vertices_;
};

#endif //GRAPH_H