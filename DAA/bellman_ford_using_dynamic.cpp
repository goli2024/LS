#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
    Edge(int s, int d, int w) : source(s), destination(d), weight(w) {}
};

void generateGraph(vector<vector<Edge>> &graph, int V, const vector<Edge> &edges) {
    for (const Edge &e : edges) {
        graph[e.source].push_back(e);
    }
}

void bellmanFord(const vector<vector<Edge>> &graph, int V, int source) {
    vector<int> dis(V, numeric_limits<int>::max());
    dis[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (const Edge &e : graph[u]) {
                if (dis[u] != numeric_limits<int>::max() && dis[u] + e.weight < dis[e.destination]) {
                    dis[e.destination] = dis[u] + e.weight;
                }
            }
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if (dis[i] == numeric_limits<int>::max()) {
            cout << i << "\t\tINF" << endl;
        } else {
            cout << i << "\t\t" << dis[i] << endl;
        }
    }
}

int main() {
    int V, E, source;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the source vertex: ";
    cin >> source;

    vector<vector<Edge>> graph(V);
    vector<Edge> edges;
    
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back(Edge(src, dest, weight));
    }

    generateGraph(graph, V, edges);
    bellmanFord(graph, V, source);

    return 0;
}
