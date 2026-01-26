#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> adj; 
vector<int> parent;
vector<bool> visited;

void DFS(int curr) {
    visited[curr] = true;

    for (int next : adj[curr]) {
        if (!visited[next]) {
            parent[next] = curr; 
            DFS(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    adj.resize(N+1);
    parent.resize(N + 1, 0);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}
