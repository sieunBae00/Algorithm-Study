#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> gstation; // 주유소 저장 배열
	priority_queue<int, vector<int>, less<int>> oil;

	int ans = 0; // 주유소 들린 횟수

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		gstation.push_back({ a, b });
	}

	sort(gstation.begin(), gstation.end()); // 거리 가까운 순으로 주유소 위치 정렬

	int L, P;
	cin >> L >> P;

	int numofg = 0; // gstation 배열의 인덱스

	while(P < L) { // 마을에 도착하지 못한 동안 반복

		// 도달 가능한 거리 내의 연료 모두 저장
		while ((numofg < N) && (gstation[numofg].first <= P)) {
			oil.push(gstation[numofg].second); // 지나친 주유소의 연료통 저장
			numofg++;
		}

		// 마을에 도착하지 못했다면 (연료 소진)

		if (oil.empty()) { // 남은 연료가 없다면 -> 마을에 도달 불가
			cout << -1 << '\n'; // 1을 출력하고 끝.
			return 0;
		}

		// 연료가 남아있는 경우
		P += oil.top(); // 연료통 중 가장 큰 것을 연료로 사용한다. (도달가능거리 증가)
		oil.pop();
		ans++;
	}

	cout << ans << '\n';

	return 0;
}