#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include <queue>

vector<vector<int>> graph;

int N, M;

int BFS(int st) {
	vector<int> dist; // 거리를 담을 배열
	vector<int> visited; // 방문여부 & 거쳐온 간선 수 저장 배열

	dist.resize(N + 1);
	visited.resize(N + 1, false);

	queue<int> q; // BFS 를 위한 큐 선언

	dist[st] = 0; // 자기자신으로의 거리는 0

	// 방문 처리 후 큐에 넣는다 
	visited[st] = true;
	q.push(st);

	while (!q.empty()) {
		// 다음 노드를 설정하고 pop()
		int next = q.front();
		q.pop();

		for (int nn : graph[next]) {
			if (!visited[nn]) {
				// 방문 처리 후 큐에 넣는다 
				visited[nn] = true;
				q.push(nn);

				dist[nn] = dist[next] + 1; // (현재 위치까지 걸린 거리) + 1 !!
			}
		}
	}

	int bacon = 0;
	for (int i = 1; i < dist.size(); i++) {
		bacon += dist[i]; // 케빈 베이컨 수 계산
	}

	return bacon;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> ans; // 노드 별 케빈베이컨 수 저장 배열

	cin >> N >> M;

	graph.resize(N + 1);
	ans.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		// 관계 저장
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		ans[i] = {BFS(i), i}; // {케빈베이컨 수, 노드 번호}
	}

	sort(ans.begin(), ans.end()); // 케빈베이컨 수 기준, 케빈베이컨 수가 같다면 노드 번호 기준 정렬

	cout << ans[1].second << '\n'; // 노드 번호 출력

	return 0;
}