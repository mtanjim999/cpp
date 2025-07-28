#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v) where 0 <= u,v < " << V << ":\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Omit this for directed graph
    }

    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    vector<bool> visited(V, false);

    cout << "DFS Traversal starting from node " << start << ": ";
    dfs(start, adj, visited);
    cout << endl;

    return 0;
}
