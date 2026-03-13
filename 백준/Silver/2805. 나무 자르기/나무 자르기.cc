#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int N, M;
vector<int> height;
int max_h(0);

int solve() {
	int min(0), max(max_h);
	int mid;
	int ans = 0;

	while (min <= max) {
		mid = (min + max) / 2;

		long long curr_length = 0; // 현재 가져갈 수 있는 나무의 길이 (자료형 주의!)

		for (int i = 0; i < height.size(); i++) {
			if (height[i] > mid) curr_length += height[i] - mid;
		}

		if (curr_length == M) return mid;
		else if (curr_length > M) { // 과하게 가져가는 상황 -> 높이를 높인다.
			ans = mid; // 그러나 어쩌면 현재의 높이가 최소한의 낭비인 상황 일 수도 있으므로 mid 를 저장
			min = mid + 1;
		}
		else max = mid - 1; // 나무가 부족한 상황 -> 높이를 낯춘다.
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	height.resize(N);

	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;

		if (h > max_h) max_h = h; // 나무 중 가장 큰 것의 높이

		height[i] = h; // 높이를 배열에 저장
    }

	int ans = solve();

	cout << ans << '\n';

	return 0;
}