#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x;

	typedef pair<int, int> num;

	priority_queue<num, vector<num>, greater<num>> pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else {
			if (x < 0) pq.push({ abs(x), x });
			else pq.push({ x, x });
		}
	}

	return 0;
}