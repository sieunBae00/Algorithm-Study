#include <iostream>
using namespace std;
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> hap;
	vector<long long> rem;

	long long ans = 0;

	int N, M;
	cin >> N >> M;

	hap.resize(N + 1, 0);
	rem.resize(M, 0);

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		hap[i] = hap[i - 1] + n; // 누적합 저장
	}
	
	for (int i = 1; i <= N; i++) {
		hap[i] %= M; // M으로 나누었을 때 나머지 저장
	}

	for (int i = 1; i <= N; i++) {
		int curr = hap[i]; // curr 는 0~ M-1 사이 정수
		rem[curr]++; // 각 나머지(0~ M-1) 이 몇 개인지 센다
	}

	for (int i = 0; i < M; i++) {
		if (i == 0) { // 나머지가 0인 것들
			ans += rem[i]; // 그 자체(i==j) 로도 M으로 나누어 떨어지므로 ans에 더하기
		}
		if (rem[i] >= 2) { // 나머지가 같은 칸이 2개 이상이라면
			ans += rem[i] * (rem[i] - 1) / 2; // "X개 중 2개를 택하는 경우의 수" 계산, ans 에 더하기
		}
	}
	cout << ans << '\n';

	return 0;
}