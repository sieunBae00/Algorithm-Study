#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main() {

	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int start, end;
	cin >> start >> end;

	int m;
	cin >> m;

	vector<vector<int>> adj(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	vector<int> dist(n + 1, -1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == end) {
			break;
		}

		for (int next : adj[curr]) {
			if (dist[next] == -1) {
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}
	cout << dist[end] << '\n';

	return 0;
}