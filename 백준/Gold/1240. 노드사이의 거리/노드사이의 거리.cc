#include <iostream>
using namespace std;
#include<vector>

typedef pair<int, int> p;

vector<vector<p>> dist;
vector<bool> visited;

int ans;

void trip(int s, int e, int res) {
	visited[s] = true;

	for (p next : dist[s]) {
		if (next.first == e) {
			ans = res + next.second;
			return; 
		}
		if (!visited[next.first]) {
			trip(next.first, e, res + next.second);
		}
	}
	return;
}

int main() {
	int N, M;
	cin >> N >> M;

	dist.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v, d;
		cin >> u >> v >> d;

		dist[u].push_back(make_pair(v, d));
		dist[v].push_back(make_pair(u, d));
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		visited.assign(N+1, false);

		ans = 0;
		trip(s, e, 0);
		cout << ans << "\n";
	}

	return 0;

}
