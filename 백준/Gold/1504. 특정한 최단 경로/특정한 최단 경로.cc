#include <iostream>
using namespace std;
#include<vector>
#include<queue>

typedef pair<int, int> edge;
const int INF = 10000000; // 충분히 큰 값

vector<vector<edge>> slist;
vector<bool> visited;

int N, E;

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

		for (edge e : slist[nn]) { // (노드, 가중치)
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;

	slist.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		// 양방향 그래프
		slist[u].push_back(make_pair(v, w)); // (노드, 가중치)
		slist[v].push_back(make_pair(u, w)); // (노드, 가중치)
	}

	int v1, v2;
	cin >> v1 >> v2; // 거쳐야 하는 정점 

	vector<int> dist1 = dijkstra(1); // 1->v1, 1->v2 구하기
	vector<int> distv1 = dijkstra(v1); // v1->v2, v1->N 구하기
	vector<int> distv2 = dijkstra(v2); // v2->v1, v2->N 구하기

	long long pathA = dist1[v1] + distv1[v2] + distv2[N]; // 1 -> v1 -> v2 -> N
	long long pathB = dist1[v2] + distv2[v1] + distv1[N]; // 1 -> v2 -> v1 -> N

	int ans;
	// 둘 중 작은 경로 출력
	if (pathA < pathB) ans = pathA;
	else ans = pathB;

	// 경로가 있는지 확인(INF 보다 값이 크다면, 경로가 없으므로 -1 출력)
	if (ans >= INF) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}