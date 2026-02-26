#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> V; // 끝나는 시간 기준 정렬
	int ans = 0;

	int N;
	cin >> N;

	V.resize(N);

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;

		V[i] = { e, s }; // 끝나는 시간을 first 로 해서 저장
	}

	sort(V.begin(), V.end()); // 끝나는 시간 기준 정렬 (빨리 끝나는 것부터)

	int end = V[0].first; // 현재 끝나는 시간
	ans++;

	for (int i = 1; i < V.size(); i++) {
		if (end <= V[i].second) { // 현재 끝나는 시간 <= 다음 회의의 시작 시간 이라면 (다음 회의 진행 가능)
			end = V[i].first; // 다음 회의가 끝나는 시간으로 end 를 업데이트
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}