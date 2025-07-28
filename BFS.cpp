#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
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
        adj[v].push_back(u); // Omit this line for directed graph
    }

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;

    bfs(start, adj, V);

    return 0;
}

