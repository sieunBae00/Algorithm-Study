#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> dist;
vector<bool> visited;

int ans;
bool cycle;

void DFS(int curr, int par) {
	visited[curr] = true;

	for (int node : dist[curr]) {
		if (visited[node] && node != par) {
			cycle = true;
			return;
		}
		if (!visited[node]) DFS(node, curr);
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int casenum = 0;

	while (true) {
		casenum++;

		int n, m;
		cin >> n >> m;

		if ((n == 0) && (m == 0)) return 0;

		ans = 0;
		
		dist.clear();
		dist.resize(n + 1);
		visited.clear();
		visited.resize(n + 1, false);

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;

			dist[u].push_back(v);
			dist[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				ans++;
				cycle = false;

				DFS(i, 0);
				if (cycle) ans--;
			}
		}

		switch (ans) {
		case 0:
			cout << "Case " << casenum << ": " << "No trees." << '\n';
			break;
		case 1:
			cout << "Case " << casenum << ": " << "There is one tree." << '\n';
			break;
		default:
			cout << "Case " << casenum << ": " <<  "A forest of " << ans << " trees." << '\n';
			break;
		}
		
	}

	return 0;
}