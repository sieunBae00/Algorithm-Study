#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> dist;
vector<bool> visited;
vector<bool> isLeaf;
int ans;

void findLeaf(int root, int d) {
	visited[root] = true;

	if (isLeaf[root]) {
		ans += d;
		return;
	}

	for (int next : dist[root]) {
		if (!visited[next]) findLeaf(next, d + 1);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	ans = 0;

	dist.resize(N + 1);
	visited.resize(N + 1, false);
	isLeaf.resize(N + 1, false);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		dist[a].push_back(b);
		dist[b].push_back(a);
	}

	for (int i = 2; i < N + 1; i++) {
		if (dist[i].size() == 1) {
			isLeaf[i] = true;
		}
	}

	findLeaf(1, 0);

	if (ans % 2 == 0) cout << "No" << '\n';
	else cout << "Yes" << '\n';

	return 0;
}