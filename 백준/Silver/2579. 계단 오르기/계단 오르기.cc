#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> stairs;
	vector<int> f;

	int n;
	cin >> n;

	stairs.resize(n + 1);
	f.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int sc;
		cin >> sc;

		stairs[i] = sc; // 계단의 점수 저장
	}

	f[1] = stairs[1];
	f[2] = stairs[1] + stairs[2];

	for (int i = 3; i <= n; i++) {
		f[i] = max(f[i - 2] + stairs[i], f[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << f[n] << '\n';

	return 0;
}