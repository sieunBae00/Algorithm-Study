#include <iostream>
using namespace std;
#include <queue>

typedef pair<int, int> p;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		queue<p> q;
		priority_queue<int, vector<int>> pq;
		int ans = 0;

		int N, M;
		cin >> N >> M;

		for (int j = 0; j < N; j++) {
			int imp;
			cin >> imp;

			q.push(make_pair(j, imp));
			pq.push(imp);
		}

		while (true) {
			while (q.front().second < pq.top()) {
				p curr = q.front();
				q.pop();
				q.push(curr);
			}			
			ans++;

			if (q.front().first == M) break;

			q.pop();
			pq.pop();
		}

		cout << ans << '\n';
	}
	return 0;
}