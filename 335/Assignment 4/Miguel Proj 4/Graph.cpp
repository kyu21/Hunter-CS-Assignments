/*
	name: Miguel Acero
	Graph file functinos
*/

#include "Graph.h"
#include "Comparator.h"

double Graph::getWeight(int &from, int &to) {
	if (!isAdj(from,to)) return -1;
	auto v = vertices.find(from);
	return v -> second.adj.find(to) -> second;
}	
//returns cost of vertex
double Graph::getCost(const int v) {
	// return vertices[v].distance;
	return vertices[v].distance;
}

void Graph::addVertex(const int &val) {
	// vertices[val] = -1;
	// inserts the vertex pair into the map 
	vertices.insert(pair<int, vertex>(val, vertex(val)));
}

void Graph::addEdge(const int &from, const int &to, const double &weight) {
	auto v = vertices.find(from);
	v -> second.adj.insert(std::pair<int, double>(to, weight));
}

//true if vertex exists
bool Graph::exists(const int &v) {
	if(vertices.find(v) == vertices.end()) return false;
	return true;
}

// checks if two is inside one's adjacency list
bool Graph::isAdj(const int &one, const int &two) {
	auto v = vertices.find(one);
	if (!exists(one) || !exists(two)) return false;
	if (v -> second.adj.find(two) == v -> second.adj.end())	return false;
	return true;
}

//prints a linked list of the shortest path for each vertex.
void Graph::printPath(const int v) {
	list<int> path;
	if (!exists(v)) cout << "error could not find vertex";
	vertex *vert = &vertices.find(v) -> second;
	while(vert != nullptr) {
		path.push_front(vert -> value);
		vert = vert -> path;
	}
	for (auto &x: path) cout << x << " ";
}

void Graph::Dijkstra(const int &originVec) {
	//stores pointers to the vertices in the graph
	std::priority_queue<vertex*, std::vector<vertex*>, Comparator<vertex*>> pq;
	if (!exists(originVec)) { cout << "this vector does not exist."; exit(1); }
	const double DOUBLE_MAX = std::numeric_limits<double>::infinity();
	for (auto &v: vertices){
		v.second.distance = DOUBLE_MAX;
		v.second.known = false;
	}
	auto vec = vertices.find(originVec);
	vec -> second.distance = 0; //origin vec always at 0

	pq.push(&vec -> second);

	for(;;) {
		vertex *v = nullptr;
		bool fin = false;
		while (!pq.empty() && !fin) {
			v = pq.top();
			pq.pop();
			if(!v -> known) fin = true;
		}
		if (!fin) break;
		v -> known = true;

		for (auto adj : v->adj)	{
			auto next = vertices.find(adj.first);
			if (next -> second.distance > v -> distance + adj.second) {
				next -> second.distance = v -> distance + adj.second;
				next -> second.path = v;
				pq.push(&next -> second);
			}
		}
	}

	for(int i = 1; i <= vertices.size(); i++) {
		if (i == originVec) cout << i << ": " << i << " (Cost:0)" << endl;
		else {
			double cost = getCost(i);
			if (cost == DOUBLE_MAX)
				cout << i << ": No path available" << endl;
			else {
				cout << i << ": ";
				printPath(i);
				cout << " (Cost: " << cost << ")" << endl;
			}
		}
	}
}

//sorts graph topologically, and couts by sorted indegree size 
void Graph::topSort() {
	// the indegree of a vector is a counter of how many vectors are pointing to it
	queue<int> q;
	bool cyclic = true;
	int counter = 0;
	//sets the indegrees
	for(auto &i: vertices) {
		int val = i.first;
		for (auto &j: vertices) {
			if (j.second.adj.find(val) != j.second.adj.end()) {
				i.second.indegree++;
			}
		}
	}
	for(auto &j: vertices) {
		if (j.second.indegree == 0) q.push(j.first);
		if (j.second.indegree != 0) counter++;
	}
	if (counter != vertices.size()) cyclic = false;

	list<int> order;
	if (cyclic == true) {
		cout << "Cycle Found" << endl;
	}

	else {
		while(!q.empty()) {
			int f = q.front();
			q.pop();
			order.push_back(f);
			auto adjacent = vertices.find(f) -> second.adj;
			for(auto &a: adjacent) {
				if(--(vertices.find(a.first) -> second.indegree) == 0)
					q.push(a.first);
			}
		}
	}

	for(auto &i : order) cout << i << " ";
	cout << endl;
}
