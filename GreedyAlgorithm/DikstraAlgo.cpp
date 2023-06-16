#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

struct Edge {
    int destination;
    int weight;
};

void dijkstraShortestPath(int source, const vector<vector<Edge>>& graph, vector<int>& distances) {
    int numVertices = graph.size();
    distances.resize(numVertices, INF);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    int numVertices = 6;
    vector<vector<Edge>> graph(numVertices);

    // Add edges to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 6});
    graph[2].push_back({3, 3});
    graph[2].push_back({4, 4});
    graph[3].push_back({4, 2});
    graph[3].push_back({5, 6});
    graph[4].push_back({5, 1});

    int source = 0;
    vector<int> distances;

    dijkstraShortestPath(source, graph, distances);

    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (distances[i] == INF) {
            cout << "INF\n";
        } else {
            cout << distances[i] << "\n";
        }
    }

    return 0;
}
