#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M;
		cin >> M;

		cout << M / 2 + 1 << '\n';

		priority_queue<int, vector<int>, less<int>> pq_1; // 작은 쪽 - 큰 수가 top()
		priority_queue<int, vector<int>, greater<int>> pq_2; // 큰 쪽 - 작은 수가 top()

		int cnt_print = 0;

		for (int j = 0; j < M; j++) {
			int n;
			cin >> n;

			if (j % 2 == 0) pq_1.push(n);
			else pq_2.push(n);

			if (!pq_2.empty() && (pq_1.top() > pq_2.top())) { // 작은 쪽 중 가장 큰 값이 큰 쪽의 가장 작은 값보다 크면
				int tmp1 = pq_1.top();
				int tmp2 = pq_2.top();
				pq_1.pop();
				pq_2.pop();
				pq_1.push(tmp2); // 두 top() 을 바꾸어 반대쪽 큐에 넣는다.
				pq_2.push(tmp1);
			}

			if (j % 2 == 0) {
				cout << pq_1.top() << " ";
				cnt_print++;

				if (cnt_print % 10 == 0) {
					cout << '\n';
				}
			}
		}
		cout << '\n';
	}

	return 0;
}