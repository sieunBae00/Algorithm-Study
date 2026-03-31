#include <iostream>
using namespace std;
#include <vector>

vector<int> length;

int solve(long long mid) {
	long long res = 0;
	for (int i : length) {
		res += i / mid;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	long long sum(0);

	for (int i = 0; i < K; i++) {
		int k;
		cin >> k;

		sum += k;
		length.push_back(k);
	}

	long long max = sum / N; // 랜선 길이의 범위의 최댓값
	long long min(1), mid(0);
	long long ans = 0;

	while (min <= max) {
		mid = (min + max) / 2;

		if (solve(mid) < N) { // 현재 mid 로 잘랐을 때 N 개를 못 채운다면
			max = mid - 1; // 좀 더 작게 자르기
		}
		else { // N개와 같거나, 남는다면
			min = mid + 1; // 좀 더 크게 잘라보기
			ans = mid;
		}
	}
	cout << ans << '\n';

	return 0;
}