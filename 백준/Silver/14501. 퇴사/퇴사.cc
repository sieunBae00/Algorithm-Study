#include <iostream>
using namespace std;
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> Schedule;
	vector<int> dp; // dp[i]: i번째 날까지 일했을 때의 최대 이익

	int N;
	cin >> N;

	Schedule.resize(N + 1);
	dp.resize(N + 2, 0); // 0~N+1 까지의 배열이 있어야 함! (n번쨰 날에 일을 마쳤다면, 급여는 n+1 일째에)

	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;

		Schedule[i] = { T, P };
	}


	for (int i = 1; i <= N; i++) { // 1일차~N일차 까지 반복
		// 일 안할 경우
		dp[i+1] = max(dp[i], dp[i+1]);

		int payday = i + Schedule[i].first;

		//일 할 경우
		if (payday <= N + 1) { // 급여가 퇴사일보다 후에 들어오면 안 됨
			dp[payday] = max(dp[payday], dp[i] + Schedule[i].second);
		}
	}

	cout << dp[N + 1] << '\n';

	return 0;
}