#include <bits/stdc++.h>
using namespace std;

int graph[100][100];

int findmin(int weight[], bool visited[], int n) {
    int minWeight = INT_MAX, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && weight[i] < minWeight) {
            minWeight = weight[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void findmst(int graph[][100], int v, int start) {
    int parent[v], weight[v];
    bool visited[v] = {false};

    for (int i = 0; i < v; i++) {
        weight[i] = INT_MAX;
    }

    weight[start] = 0;
    parent[start] = -1;

    for (int i = 0; i < v - 1; i++) {
        int u = findmin(weight, visited, v);
        visited[u] = true;

        for (int j = 0; j < v; j++) {
            if (graph[u][j] && !visited[j] && graph[u][j] < weight[j]) {
                parent[j] = u;
                weight[j] = graph[u][j];
            }
        }
    }

    int mst=0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++) {
        mst = mst+graph[i][parent[i]];
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
    cout<<"\nCost of MST is : "<<mst<<endl;
}

int main() {
    int v, e, start;
    cout << "number of vertices and edges: ";
    cin >> v >> e;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "\nEnter edges (vertex1 vertex2 weight):\n";
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        graph[x][y] = w;
        graph[y][x] = w;
    }

    cout << "Starting node: \n";
    cin >> start;

    findmst(graph, v, start);

    return 0;
}
