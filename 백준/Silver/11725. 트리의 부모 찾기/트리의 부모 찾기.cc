#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> tree;
vector<bool> visited;
vector<int> parent;


void DFS(int r) {
	visited[r] = true;

	for (int i : tree[r]) {
		if (!visited[i]) {
			parent[i] = r;
			DFS(i);
		}
	}
}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

	int N;
	cin >> N;

	tree.resize(N + 1);
	visited.resize(N + 1, false);
	parent.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	DFS(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}