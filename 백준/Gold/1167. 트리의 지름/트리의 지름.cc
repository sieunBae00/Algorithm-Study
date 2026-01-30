#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<Edge> adj[100001];
bool visited[100001];
int maxDist = 0;
int maxNode = 0;

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        maxNode = node;
    }

    for (auto& edge : adj[node]) {
        if (!visited[edge.to]) {
            dfs(edge.to, dist + edge.weight);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    cin >> V;

    for (int i = 0; i < V; i++) {
        int u;
        cin >> u;
        while (true) {
            int v, w;
            cin >> v;
            if (v == -1) break;
            cin >> w;
            adj[u].push_back({v, w});
        }
    }

    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(maxNode, 0);

    cout << maxDist << "\n";

    return 0;
}