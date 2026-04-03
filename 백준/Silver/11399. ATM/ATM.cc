#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> time;

	int N;
	cin >> N;

	time.resize(N);

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;

		pq.push(p);
	}

	time[0] = pq.top(); // 벡터의 범위 벗어나는 것을 방지하기 위해, 첫 사람은 따로 저장
	pq.pop();

	for (int i = 1; i < N; i++) {
        int curr = pq.top();
		pq.pop();
		
		time[i] = time[i - 1] + curr; // 앞 사람이 기다린 시간에 내가 걸리는 시간을 누적해서 더한다
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += time[i];
	}

	cout << ans << '\n';

	return 0;
}