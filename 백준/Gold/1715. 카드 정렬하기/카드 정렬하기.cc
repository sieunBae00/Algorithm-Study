#include <iostream>
using namespace std;
#include <queue>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;

		pq.push(c);
	}

	int ans = 0;

	while (pq.size() > 1) {
		int c1 = pq.top();
		pq.pop();
		int c2 = pq.top();
		pq.pop();

		pq.push(c1 + c2);
		ans += c1 + c2;
	}

	cout << ans << '\n';
    
    return 0;
}