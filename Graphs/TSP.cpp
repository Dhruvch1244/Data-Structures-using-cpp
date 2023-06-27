#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculatePathCost(const vector<int>& path, const vector<vector<int>>& graph) {
    int cost = 0;
    int n = path.size();
    
    for (int i = 0; i < n - 1; ++i) {
        int src = path[i];
        int dest = path[i + 1];
        cost += graph[src][dest];
    }
    
    int lastCity = path[n - 1];
    int firstCity = path[0];
    cost += graph[lastCity][firstCity];
    
    return cost;
}

int tspBruteForce(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        path[i] = i;
    }
    
    int minCost = INT_MAX;
    
    do {
        int pathCost = calculatePathCost(path, graph);
        minCost = min(minCost, pathCost);
    } while (next_permutation(path.begin() + 1, path.end()));
    
    return minCost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int minCost = tspBruteForce(graph);
    
    cout << "Minimum cost: " << minCost << endl;
    
    return 0;
}
