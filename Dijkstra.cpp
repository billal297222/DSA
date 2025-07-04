#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> // (distance, node)

void dijkstra(int start, vector<vector<pii>>& adj, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
        }
      }

    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1); // 1-indexed graph
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<int> dist(n + 1, INT_MAX);
    dijkstra(start, adj, dist);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX)
            cout << i << ": unreachable\n";
        else
            cout << i << ": " << dist[i] << "\n";
    }

    return 0;
}
