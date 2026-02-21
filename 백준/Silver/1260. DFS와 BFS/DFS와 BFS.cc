#include <iostream>
using namespace std;
#include<vector>
#include<queue>

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int root) {
	visited[root] = true;
	cout << root << " ";

	for (int next : graph[root]) {
		if (!visited[next]) DFS(next);
	}
	return;
}

void BFS(int root) {
	queue<int> q;
	q.push(root);
	visited[root] = true; // root 큐에 넣으며 방문 처리

	while (!q.empty()) {
		int next = q.front();
		cout << next << " ";
		q.pop();

		for (int nn : graph[next]) {
			if (!visited[nn]) {
				q.push(nn);
				visited[nn] = true; // 큐에 넣으면 방문 처리
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	graph.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());  // 각 노드에 연결된 간선을 노드 번호에 따라 정렬
	}

	DFS(V);
	cout << '\n';
	visited.assign(N+1, false); // visited 배열 초기화
	BFS(V);

	return 0;
}
