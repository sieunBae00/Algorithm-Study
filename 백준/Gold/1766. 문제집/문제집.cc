#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> edgenum(N + 1, 0);
	vector<vector<int>> adj(N + 1);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		edgenum[B]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= N; i++) {
		if (edgenum[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int curr = pq.top();
		pq.pop();

		cout << curr << " ";

		for (int next : adj[curr]) {
			edgenum[next]--;
			if (edgenum[next] == 0) {
				pq.push(next);
			}
		}
	}

	return 0;
}