#include "Graph.h"
#include "disjoint_sets.cc"

void Graph::addVertex(const int &val) {
	vertices_.insert(pair<int, vertex>(val, vertex(val)));
}

void Graph::addEdge(const int &from, const int &to, const double &weight) {
	auto vertex = vertices_.find(from);
	vertex->second.adj_list.insert(pair<int, double>(to, weight));
}

double Graph::getWeight(const int &from, const int &to) const {
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

double Graph::getDistance(const int &v) {
	return vertices_[v].distance;
}

int Graph::getOutdegree(const int &v) const {
	return vertices_.find(v)->second.outdegree;
}

void Graph::printGraph() const {
	// for (auto &v : vertices_) {
	// 	cout << v.first << ":" << endl;
	// 	for (auto v2 : v.second.adj_list) {
	// 		cout << v2.first << " " << v2.second << endl;
	// 	}
	// 	cout << endl;
	// }
	for (auto &v : vertices_) {
		cout << v.first << ": ";
		for (auto v2 : v.second.adj_list) {
			cout << v2.first << " ";
		}
		cout << endl;
	}
}

// Print the shortest path
void Graph::printPath(const int &v) {
	list<int> path;
	// Check if vertex exists
	if (!isVertexExist(v)) {
		cout << "Vertex not found." << endl;
		exit(1);
	}

	// Get vertex and initialize path
	vertex *v2 = &vertices_.find(v) -> second;
	while (v2 != nullptr) {
		path.push_front(v2->value);
		v2 = v2->next;
	}

	// Print path
	for (auto &x : path) {
		cout << x << ", ";
	}
}


// Compare class to use for priority queue
template<class T>
class Comparator {
public:
	bool operator() (const T &a, const T &b) {
		return (a->distance > b->distance);
	}
};

void Graph::performDijkstra(const int &start) {
	// inifnity
	const int MAX_VALUE = numeric_limits<int>::max();

	// Check if valid starting index
	if (!(isVertexExist(start))) {
		cout << "Invalid starting vertex." << endl;
		exit(1);
	}

	// Intialize queue and vertices to unknown distances
	priority_queue<vertex*, vector<vertex*>, Comparator<vertex*>> queue;
	for (auto &v : vertices_) {
		v.second.distance = MAX_VALUE;
		v.second.known = false;
	}

	// Distance to first vertex is 0
	auto v0 = vertices_.find(start);
	v0->second.distance = 0;
	queue.push(&v0->second);

	while (true) {
		vertex *current_vertex = nullptr;
		bool done = false;

		// While queue is not empty and algorithm is not done
		// Get top vertex of queue and pop from queue
		// Check if its distance is known
		while (!queue.empty() && !done) {
			current_vertex = queue.top();
			queue.pop();
			if (!(current_vertex->known)) {
				done = true;
			}
		}

		// If vertex is unknown, break
		if (!done) {
			break;
		}

		current_vertex->known = true;
		for (auto &adj : current_vertex->adj_list) {
			// Next neighbor vertex
			auto next_adj = vertices_.find(adj.first);
			// If the neighbor's distance is more than distance between current and neighbor, relax edge
			if (next_adj->second.distance > (current_vertex->distance + adj.second)) {
				next_adj->second.distance = current_vertex->distance + adj.second;
				next_adj->second.next = current_vertex;
				queue.push(&next_adj->second);
			}
		}
	}

	for (size_t i = 1; i <= vertices_.size(); ++i) {
		// Starting index is cost 0;
		if (i == (size_t) start) {
			cout << i << ": " << i << ", Cost: 0.0." << endl;
		}
		else {
			double distance = getDistance(i);
			if (distance == MAX_VALUE) {
				cout << i << ": No path." << endl;
			}
			else {
				cout << i << ": ";
				printPath(i);
				cout << "Cost: " << distance << "." << endl;
			}
		}
	}
}

void Graph::makeAndTestRandomGraph(const int &numNodes) {
	if (numNodes < 2) {
		cout << "Invalid number of nodes." << endl;
		exit(1);
	}

	DisjSets ds(numNodes);
	int edges = 0;

	// Add n vertices
	for (int i = 0; i < numNodes; ++i) {
		addVertex(i);
	}

	// time as random seed
	srand(time(0));

	while (!ds.hasOneSet()) {
		// Get random numbers as verteices to connect
		const int v1 = rand() % numNodes;
		const int v2 = rand() % numNodes;

		// Check if can union two verticies
		// value not equal, not adjacent to each other, and not part of same set
		if (!( (v1 == v2) || isAdjacent(v1, v2) || isAdjacent(v2, v1) || (ds.find(v1) == ds.find(v2)) )) {
			// Add edges - connect
			addEdge(v1, v2, 1);
			addEdge(v2, v1, 1);

			// Increase Outdegree
			vertices_.find(v1)->second.outdegree++;
			vertices_.find(v2)->second.outdegree++;
			edges++;

			// Union two sets
			ds.unionSets(v1, v2);
		}
	}

	// Calculating Stats
	int min = vertices_.begin()->second.outdegree;
	int max = vertices_.begin()->second.outdegree;
	double avg = 0.0;

	for (auto &v : vertices_) {
		min = std::min(min, v.second.outdegree);
		max = std::max(max, v.second.outdegree);
		avg += v.second.outdegree;
	}
	avg /= numNodes;

	// Printing Stats
	cout << "Number of edges: " << edges << endl;
	cout << "Smallest out-degree: " << min << endl;
	cout << "Largest out-degree: " << max << endl;
	cout << "Average out-degree: " << avg << endl;
}