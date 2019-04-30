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
	}
	file.close();

}

void PrintCycle(vector<int> path){
	for(unsigned int i = 0; i < path.size(); i++) {
			if(i < path.size()-1){
				cout << path[i] << ", ";
			}
			else{
				cout << path[i];
			}
	}		
}

void DetermineCycle(vector<vector<pair<int,double>>> &graph){
	
	vector<int> connections(graph.size(),0);
	for(unsigned int x = 1; x < graph.size(); x++){
		for(unsigned int i = 0; i < graph[x].size(); i++){ // if x = graph[x][i]
			connections[graph[x][i].first]++;
		}
	}
	/*
	for(unsigned int i = 1; i < connections.size(); i++){
		cout << i << ": " << connections[i] <<endl;
	}
	*/
	
	bool cycle = true;
	int indegree;
	vector<int> path;
	for(unsigned int i = 1; i < connections.size();i++){ //checks for cycle and push back path thats equal to 0 
		if(connections[i] == 0){
			cycle = false; // no cycle since one node has no connections
			indegree = i;
			connections[i] = INT_MAX; // set to max
		}
	}
	if(cycle){
		cout << "Cycle found" <<endl;
	}
	else if(!cycle){
		queue<int> que;
		que.push(indegree);
		while(!que.empty()){
			path.push_back(que.front()); // sets path
			for(unsigned int i = 0; i < graph[que.front()].size(); i++){ // gets all connections of the path we pushed 
				connections[graph[que.front()][i].first]--;
			}
			que.pop(); // pop from que since we done
			for(unsigned int i = 1; i < connections.size(); i++){ // get next node that has indegree 0
				if(connections[i] == 0){ 
					que.push(i);
					connections[i] = INT_MAX;
				}
			}
		}
		PrintCycle(path);
	}
}

int main(int argc, char **argv){
	if(argc !=2){
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << endl;
		return 0;
	}
	
	vector<vector<pair<int,double>>> graph;
	const string graph_file(argv[1]);
	ReadGraphFile(graph_file, graph);
	DetermineCycle(graph);

}