#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[start] = true;
    cout << start << " ";

    for (int neighbor : adj[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited); // recursive call
        }
    }
}

int main() {
    int n, m; 
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start, adj, visited);

    return 0;
}
