#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {

    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianCycleUtil(vector<vector<int>> &graph, vector<int> &path,
                          int pos) {
    int V = graph.size();

    if (pos == V) {

        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle(vector<vector<int>> &graph) {
    int V = graph.size();

    vector<int> path(V, -1);

    path[0] = 0;

    if (hamiltonianCycleUtil(graph, path, 1)) {
        cout << "Hamiltonian Cycle exists:" << endl;
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
    } else {
        cout << "No Hamiltonian Cycle exists." << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    hamiltonianCycle(graph);

    return 0;
}
