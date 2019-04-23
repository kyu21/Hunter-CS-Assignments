/*
	Name: Miguel Acero
	Date: May 7 2018
	Assignment 5
	Graph func file with load graph functions as well as parsing it 
*/
#ifndef GRAPH_FUNC
#define GRAPH_FUNC

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

// Deals with graphs txt files 
void loadGraph(const string &filename, Graph &g) {
	ifstream inFile(filename);
	if(inFile.fail()) { cout << " error while opening. "; }
	int num, numTwo; //vertex number, and the nums it connects to
	double weight; 
	string line;
	getline(inFile, line); //skips the first line since it just says how many vertices there will be;
	while(getline(inFile, line)) {
		stringstream ss(line);
		ss >> num;
		g.addVertex(num);
		while(ss >> numTwo >> weight) {
			g.addVertex(numTwo);
			g.addEdge(num, numTwo, weight);
		}
	}
}

void queryGraph(const string &filename, Graph &g) {
	ifstream inFile(filename);
	int v1, v2;
	double weight = 0;
	string line;
	if(inFile.fail()) { exit(1); }
	while(inFile >> v1 >> v2) {
		if (g.isAdj(v1,v2)) weight = g.getWeight(v1, v2);
		if (weight != 0) {
			cout << v1 << " " << v2 << ": Connected, weight of edge is " << weight << endl;
			weight = 0;
		}
		else 
			cout << v1 << " " << v2 << ": Not connected" << endl;
	}
}

#endif //GRAPH_FUNC