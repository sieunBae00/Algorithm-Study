#include <iostream>
using namespace std;
#include<vector>

vector<vector<int>> V;
vector<bool> visited;
int ans = 0;

void findVirus(int root) {
	visited[root] = true;

	for (int next : V[root]) {
		if (!visited[next]) {
			ans++;
			findVirus(next);
		}
	}

	return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	V.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		V[u].push_back(v);
		V[v].push_back(u);
	}

	findVirus(1);

	cout << ans << '\n';

	return 0;
}