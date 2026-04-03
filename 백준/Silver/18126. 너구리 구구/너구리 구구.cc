#include <iostream>
using namespace std;
#include <vector>
#include <queue>

vector<vector<pair<int, long long>>> graph;
vector<bool> visited;
int N;
priority_queue<long long, vector<long long>, less<long long>> pq;


void solve(int root, long long dist) { // 현재 노드, 현재까지 온 거리
	visited[root] = true;

	if (root != 1 && graph[root].size() == 1) { // 리프 노드일 경우
		pq.push(dist);
	}
	else { // 리프 노드가 아닐 경우
		for (pair<int, long long> p : graph[root]) { // 방문하지 않은 노드(자식) 으로 내려가기
			if(!visited[p.first]) solve(p.first, dist + p.second);
		}
	}
	
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	graph.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		long long c;
		cin >> a >> b;
		cin >> c;

		graph[a].push_back({ b, c }); // {노드, 거리}
		graph[b].push_back({ a, c });
	}

	solve(1, 0);

	if (pq.empty()) cout << 0 << '\n'; // 노드가 루트 노드 하나만 있을 경우에 대한 예외처리
	else cout << pq.top() << '\n';

	return 0;
}