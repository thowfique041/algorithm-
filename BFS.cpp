#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cout << "Number of vertices and edges: ";
    cin >> v >> e;

    // Create a graph represented by an adjacency matrix
    vector<vector<int>> g(v, vector<int>(v, 0));

    int x, y;
    cout << "Enter connected vertices (0-indexed):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        g[x][y] = 1;   // Mark edge from x to y
        g[y][x] = 1;   // Since the graph is undirected, also mark y to x
    }

    // Vector to track visited nodes
    vector<bool> p(v, false);  // false means not visited

    int start;
    cout << "Enter start vertex (0 to " << v - 1 << "): ";
    cin >> start;

    // Validate start vertex
    if (start < 0 || start >= v) {
        cout << "Invalid start vertex. Please enter a value between 0 and " << v - 1 << "." << endl;
        return 1;  // Exit the program if the input is invalid
    }

    queue<int> q;
    q.push(start);
    p[start] = true;  // Mark the starting vertex as visited

    cout << "BFS path--> ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Explore all adjacent vertices of the current node
        for (int i = 0; i < v; i++) {
            if (g[node][i] == 1 && !p[i]) {  // Check if it's connected and not visited
                p[i] = true;  // Mark as visited
                q.push(i);    // Add to queue for exploration
            }
        }
    }

    cout << endl;
    
}
