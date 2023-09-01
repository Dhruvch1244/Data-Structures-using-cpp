#include <climits>
#include <iostream>
#include <set>
#include <vector>

#define INF INT_MAX

using namespace std;

void dijkstra(const vector<vector<pair<int, int>>> &graph, int source) {
    int n = graph.size();

    vector<int> distance(n, INF);
    distance[source] = 0;
    set<int> visited;

    // Main loop
    for (int i = 0; i < n; i++) {
        int minDist   = INF;
        int minVertex = -1;

        for (int j = 0; j < n; j++) {
            if (!visited.count(j) && distance[j] < minDist) {
                minDist   = distance[j];
                minVertex = j;
            }
        }

        visited.insert(minVertex);

        for (const auto &neighbor : graph[minVertex]) {
            int v      = neighbor.first;
            int weight = neighbor.second;

            if (!visited.count(v) && distance[minVertex] != INF &&
                distance[minVertex] + weight < distance[v]) {
                distance[v] = distance[minVertex] + weight;
            }
        }
    }

    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (distance[i] != INF) {
            cout << "Vertex " << i << ": " << distance[i] << endl;
        } else {
            cout << "Vertex " << i << ": unreachable" << endl;
        }
    }
}

int main() {

    vector<vector<pair<int, int>>> graph = {{{1, 4}, {2, 1}},
                                            {{3, 2}},
                                            {{1, 9}, {3, 3}},
                                            {{4, 7}},
                                            {{0, 6}, {2, 5}, {3, 2}}};

    int source = 0;

    dijkstra(graph, source);

    return 0;
}
