#include <iostream>
#include <vector>
#include <climits> // For INT_MAX (represents infinity)

using namespace std;

// Function to implement the Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph, int numVertices) {
    vector<vector<int>> dist(graph);

    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }


    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "From " << i << " to " << j << ": INF\n";
            } else {
                cout << "From " << i << " to " << j << ": " << dist[i][j] << "\n";
            }
        }
    }
}


int main() {
    int numVertices;

    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, INT_MAX));

    cout << "Enter the edges and their weights (format: source destination weight).\n";
    cout << "Enter -1 -1 -1 to finish.\n";
    int source, destination, weight;
    while (cin >> source >> destination >> weight && (source != -1 || destination != -1 || weight != -1)) {
        if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
            graph[source][destination] = weight;
        } else {
            cout << "Invalid edge entered.  Please ensure source and destination are within the valid range (0 to " << numVertices - 1 << ").\n";
        }
    }

    for (int i = 0; i < numVertices; ++i) {
        graph[i][i] = 0;
    }

    floydWarshall(graph, numVertices);

    return 0;
}


