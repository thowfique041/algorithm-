#include <bits/stdc++.h>

using namespace std;
vector<int>sum;
struct Edge {
    int src, dest, weight;
};

int findParent(vector<int>& parent, int i) {
    return (parent[i] == -1) ? i : findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);
    parent[xroot] = yroot;
}

void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V, -1);

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge& edge : edges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);

        if (x != y) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
            unionSets(parent, x, y);
            sum.push_back(edge.weight);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;

    cout << "Enter edges (src, dest, weight):\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back({src, dest, weight});
    }

    kruskalMST(edges, V);
    cout<<endl;
    cout << "Sum of weights of edges in MST is: " << accumulate(sum.begin(), sum.end(),  0) << endl;

    return 0;
}
