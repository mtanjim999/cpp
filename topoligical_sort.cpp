#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjList;

    void dfs(int vertex, vector<bool>& visited, stack<int>& result) {
        visited[vertex] = true;
        // Visit all6 neighbors
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, result);
            }
        }
        // Add current vertex to stack after visiting all neighbors
        result.push(vertex);
    }

public:
    Graph(int v) : vertices(v), adjList(v) {}

    // Add edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Perform topological sort
    vector<int> topologicalSort() {
        vector<bool> visited(vertices, false);
        stack<int> result;

        // Perform DFS for each unvisited vertex
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i, visited, result);
            }
        }

        // Convert stack to vector for topological order
        vector<int> topoOrder;
        while (!result.empty()) {
            topoOrder.push_back(result.top());
            result.pop();
        }
        return topoOrder;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(vertices);

    cout << "Enter the edges (format: u v, where u -> v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> result = g.topologicalSort();

    cout << "Topological Sort Order: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}


