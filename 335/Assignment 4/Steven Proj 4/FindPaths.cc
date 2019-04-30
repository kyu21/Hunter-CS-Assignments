//Steven Li
//Assignment 5
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <limits.h>

using namespace std;

void ReadGraphFile(const string &graph_file, vector<vector<pair<int,double>>> &graph ){
	
	string input;
	ifstream file;
	file.open(graph_file);
	int ivertex;
	file >> ivertex; // gets the number of verticies in the graph
//	cout << "ivertex " << ivertex <<endl; 
	while(getline(file,input)){
		istringstream line(input);
		int vertex = 0;
		int next_vertex = 0;
		double weight = 0;
		line >> vertex;
		graph.resize(ivertex+1); //resize graph to contain all
		while(!line.eof()){
			line >> next_vertex;
			if(next_vertex !=0){
				line >> weight;
				graph[vertex].push_back(make_pair(next_vertex,weight));
			}
		}
		/*
		for(int i = 0; i < graph[vertex].size(); i++){
			cout << vertex << " " << graph[vertex][i].first << " " << graph[vertex][i].second <<endl;
		}
		*/
	}
	file.close();
}

void PrintPaths(vector<vector<int>> path, vector<double> weight){
	
	for(unsigned int i = 1; i < path.size()-1; i++) {
		cout << i << ": ";
		for(unsigned int x = 0; x < path[i].size(); x++) {
			if(x < path[i].size()-1){
				cout << path[i][x] << ", ";
			}
			else{
				cout << path[i][x];
			}
		}
		if(weight[i] == INT_MAX){
			cout << "No Path Found" <<endl;
		}
		else{
			cout << " (Cost: " << weight[i] << ") "<<endl;
		}
	}	
}

void Dijkstra(const int starting_vertex, vector<vector<pair<int,double>>> &graph){
	
	priority_queue <pair<int,double>, vector<pair<int,double>>, greater<pair<int, double>>> que;
	vector<vector<int>> path(graph.size()+1);
	vector<bool> known(graph.size()+1, false);
	vector<double> weight(graph.size(), INT_MAX);
	
	que.push(make_pair(starting_vertex, 0));
	weight[starting_vertex] = 0;
	path[starting_vertex].push_back(starting_vertex);
	
	while(!que.empty()){
		int current_vertex = que.top().first;
		known[current_vertex] = true;
		que.pop();
		
		for(unsigned i = 0; i < graph[current_vertex].size(); i++){
			int v = graph[current_vertex][i].first;
			double w = graph[current_vertex][i].second;
			if(weight[v] > weight[current_vertex] + w){
				weight[v] = weight[current_vertex] + w;
				que.push(make_pair(v, weight[v]));
				path[v] = path[current_vertex];
				path[v].push_back(v);
			}
		}
	}
	PrintPaths(path, weight);
}


int main(int argc, char **argv){
	if(argc !=3){
		cout << "Usage: " << argv[0] << " <GRAPH_FILE> <STARTING_VERTEX>" << endl;
		return 0;
	}
	if(stoi(argv[2]) < 0){
		cout << "invalid starting vertex" <<endl;
		return 0;
	}
	
	vector<vector<pair<int,double>>> graph;
	const string graph_file(argv[1]);
	const int starting_vertex(stoi(argv[2]));
	ReadGraphFile(graph_file, graph);
	Dijkstra(starting_vertex, graph);
	
	
}