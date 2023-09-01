#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

void primMST(vector<vector<pii>> &graph, int startVertex) {
    int numVertices = graph.size();

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int>  key(numVertices, INT_MAX);
    vector<int>  parent(numVertices, -1);
    vector<bool> inMST(numVertices, false);

    pq.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto &neighbor : graph[u]) {
            int v      = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                key[v]    = weight;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<pii>> graph(numVertices);

    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }

    int startVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;

    primMST(graph, startVertex);

    return 0;
}
