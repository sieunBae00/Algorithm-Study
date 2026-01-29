#include <iostream>
using namespace std;
#include <vector>

vector<vector<pair<int, int>>> tree; // 처음 입력받은 간선과 거리 저장
vector<bool> visited;
vector<vector<pair<int, int>>> child; // 1번 노드를 루트로 가정하고 노드별 자식과 거리를 저장
vector<int> parent; // 1번 노드를 루트로 가정하고 노드별 부모를 저장
vector<int> dist; // 1번 노드 ~ 다른 모든 노드 까지의 거리
vector<int> depth; // 1번 노드를 루트로 가정하고 각 노드의 깊이 저장


void findChildDist(int r, int d, int dep) {
	visited[r] = true;
	dist[r] = d;
	depth[r] = dep;

	for (pair<int, int> c : tree[r]) {
		if (!visited[c.first]) {
			child[r].push_back(c);
			parent[c.first] = r;
			findChildDist(c.first, d + c.second, dep+1);
		}
	}

	return;
}


int findLCA(int s, int e) {
	while (true) {
		if (s == e) return s;

		if (depth[s] > depth[e]) s = parent[s];
		else e = parent[e];
	}
	
}

int calAns(int s, int e, int LCA) {
	return (dist[s] + dist[e]) - 2 * dist[LCA];
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree.resize(N + 1);
	visited.resize(N + 1, false);
    child.resize(N + 1);
	parent.resize(N + 1);
	dist.resize(N + 1);
	depth.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}

	findChildDist(1, 0, 0);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		int LCA = findLCA(s, e);

		cout << calAns(s, e, LCA) << '\n';
	}

	return 0;
}