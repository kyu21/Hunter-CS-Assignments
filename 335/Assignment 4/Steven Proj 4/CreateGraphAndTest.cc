//Steven Li
//Assignment 5
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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

void ReadQueriesFile(const string &queries_file, vector<vector<pair<int,double>>> &graph){
	string input;
	int vertex, next_vertex;
	double weight;
	ifstream file;
	file.open(queries_file);
	while(getline(file,input)){
		istringstream line(input);
		line >> vertex >> next_vertex;
		bool connected = false;
		for(unsigned int i = 0; i < graph[vertex].size(); i++){
			if(graph[vertex][i].first == next_vertex){
				weight = graph[vertex][i].second;
				connected = true;
			}
		}
		if(connected){
			cout << vertex << " " << next_vertex << " Connected, weight of edge is " << weight <<endl;
		}
		else{
			cout << vertex << " " << next_vertex << " Not Connected " << endl;
		}
	}
	file.close();

}


int main(int argc, char **argv){
	if(argc !=3){
		cout << "Usage: " << argv[0] << " <GRAPH_FILE> <ADJACENCY_QUERIES_FILE>" << endl;
		return 0;
	}
	
	vector<vector<pair<int,double>>> graph;
	const string graph_file(argv[1]);
	const string queries_file(argv[2]);
	ReadGraphFile(graph_file, graph);
	ReadQueriesFile(queries_file, graph);
}