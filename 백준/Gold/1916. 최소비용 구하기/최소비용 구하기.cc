#include <iostream>
using namespace std;
#include<vector>
#include <queue>

typedef pair<int, int> edge;
const int INF = 987654321; // 충분히 큰 값

int N, M;

vector<vector<edge>> graph;
vector<bool> visited;

vector<int> dijkstra(int st) {
	priority_queue<edge, vector<edge>, greater<edge>> q; // 다익스트라를 위한 우선순위 큐 선언

	vector<int> dist; // 거리를 담을 벡터 선언
	dist.resize(N + 1);
	std::fill(dist.begin(), dist.end(), INF); // 거리 벡터 초기회

	std::fill(visited.begin(), visited.end(), false); // 방문 벡터 초기화


	q.push(make_pair(0, st)); // (가중치, 노드) 로 우선순위 큐에 넣기
	dist[st] = 0; // 자기자신으로의 거리는 0

	while (!q.empty()) {
		edge curr = q.top(); //(가중치, 노드)
		int nn = curr.second; // 노드
		q.pop();

		if (visited[nn] == true) continue;

		visited[nn] = true;

		for (edge e : graph[nn]) { // (노드, 가중치)
			int next = e.first;
			int val = e.second;

			if (dist[next] > dist[nn] + val) {
				dist[next] = dist[nn] + val;
				q.push(make_pair(dist[next], next)); // (가중치, 노드)
			}
		}
	}

	return dist; // 거리가 담긴 벡터를 반환
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	graph.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ v, w }); // 버스는 단방향
	}

	int st, end;
	cin >> st >> end;

	auto ans = dijkstra(st);

	cout << ans[end] << '\n';

	return 0;
}