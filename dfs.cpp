#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> matrix(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] != 0) {
                adj[i].push_back(j);
            }
        }
    }

    int source, destination;
    cin >> source >> destination;
    vector<bool> visited(V, false);
    dfs(source, adj, visited);
    if (visited[destination])
        cout << "Yes Path Exists";
    else
        cout << "No Such Path";

    return 0;
}
