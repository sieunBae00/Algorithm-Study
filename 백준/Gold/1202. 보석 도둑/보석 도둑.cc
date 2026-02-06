#include <iostream>
using namespace std;
#include <queue>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	typedef pair<int, int> p;

	priority_queue<p, vector<p>, greater<p>> gem;
	priority_queue<int, vector<int>, greater<int>> bag;

	int N, K;  // 보석 수, 가방 수
	cin >> N >> K;

	long long ans = 0;

	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;

		gem.push({ m, v }); // {무게, 가격} 저장
	}

	for (int i = 0; i < K; i++) {
		int b;
		cin >> b;

		bag.push(b);
	}

	priority_queue<p, vector<p>, less<p>> cangem;

	while (!bag.empty()) {
		int weight = bag.top();

		while ((!gem.empty()) && (gem.top().first <= weight)) {
			cangem.push({ gem.top().second, gem.top().first }); // 후보 대기열에 {가격, 무게} 순으로 저장
			gem.pop();
		}

		if (!cangem.empty()) {
			ans += cangem.top().first;
			cangem.pop();
		}

		bag.pop(); 
	}

	cout << ans << '\n';

	return 0;
}