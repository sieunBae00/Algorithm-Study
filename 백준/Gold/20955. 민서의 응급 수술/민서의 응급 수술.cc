#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> graph;
vector<bool> visited;

int cycle(0), cc(0); // 사이클 수, 연결요소 수


void DFS(int curr, int pre) {
	visited[curr] = true;

	for (int next : graph[curr]) {
		if (visited[next] && next != pre) cycle++; // 사이클 개수 체크
		else if (!visited[next]) DFS(next, curr);
	}

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	graph.resize(N + 1); // 노드 번호는 1~N
	visited.resize(N + 1, false);

	// 주어진 간선 저장
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	// 연결요소 개수 체크
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			DFS(i, -1);
			cc++;
		}
	}

	cout << cycle/2 + (cc - 1) << '\n';

	return 0;
}