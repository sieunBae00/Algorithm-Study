#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> graph;
vector<bool> visited;
vector<int> flag;
bool colored;

void solve(int curr) {
    visited[curr] = true;

    for (int next : graph[curr]) {
        if (!visited[next]) {
            if (flag[curr] == flag[next]) {
                colored = false;
                break;
            }

            flag[next] = (flag[curr] + 1) % 2;
        }
    }
    for (int next : graph[curr]) {
        if(!visited[next]) solve(next);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        colored = true;

        int n, m;
        cin >> n >> m;

        graph.resize(n + 1);
        visited.resize(n + 1, false);
        flag.resize(n + 1, -1); // flag변수 -1로 초기화

        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                flag[j] = 0;
                solve(j);
            }
        }

        if (colored) cout << "possible" << '\n';
        else cout << "impossible" << '\n';

        graph.clear();
        visited.clear();
        flag.clear();
    }

    return 0;
}