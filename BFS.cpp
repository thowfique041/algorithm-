#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Initialize adjacency matrix
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    cout << "Enter the edges (u v) format:" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For an undirected graph
    }

    int start;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;

    // Perform BFS
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "Breadth First Traversal (starting from vertex " << start << "): ";
    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int i = 0; i < V; ++i) {
            if (adjMatrix[current][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}
