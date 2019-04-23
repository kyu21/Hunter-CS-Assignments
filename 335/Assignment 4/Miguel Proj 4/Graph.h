/*
	Name: Miguel Acero
	Date: May 7 2018
	Assignment 5
		Header file for Graph Class
*/
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <algorithm>
#include <cstdlib> // for exit
#include <queue> //for djikstra
#include <limits> //for dijkstras
#include <list>
#include <unordered_map>
#include <map>

using namespace std;

class Graph {
	public:
		//default big five stuff
		Graph() = default;
		~Graph() = default;	
		//copy and move stuff
		Graph &operator=(const Graph &rhs) = default;
		Graph(Graph &&rhs) = default;
		Graph &operator=(Graph &&rhs) = default;

		//accessor
		//returns the weight between two vertices
		double getWeight(int &from, int &to);
		double getCost(const int v); //returns the current cost of vertex
		bool exists(const int &v);
		bool isAdj(const int &one, const int &two);
		void printPath(const int v); //helps me visualize the current graph

		//mutator
		void addVertex(const int &val); //adds vertex num
		void addEdge(const int &from, const int &to, const double &weight);
		void Dijkstra(const int &originVec);
		void topSort();

	private:
		struct vertex {
			int value, indegree = 0;
			double distance;
			vertex* path; 
			bool known;
			unordered_map<int, double> adj; //adjacency list. holds the vertex # as well 
			vertex() : path(nullptr) {}
			vertex(int num) : value(num), path(nullptr) {}
		};
		
		map<const int, vertex> vertices;
};

#endif //GRAPH_H
