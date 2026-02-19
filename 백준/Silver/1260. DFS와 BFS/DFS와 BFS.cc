#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int curr) {
	visited[curr] = true;
	cout << curr << " ";
	for (int next : adj[curr]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";

		for (int next : adj[curr]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	adj.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	visited.assign(N + 1, false);
	dfs(V);
	cout << '\n';

	visited.assign(N + 1, false);
	bfs(V);
	cout << '\n';

	return 0;
}