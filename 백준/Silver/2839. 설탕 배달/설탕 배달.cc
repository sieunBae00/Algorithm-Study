#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int cnt_5(0), cnt_3(0);

	while (true) {
		if (N < 0) {
			cout << -1 << '\n';
			return 0;
		}

		if (N % 5 == 0) { // 5로 나누어 떨어지면
			cnt_5 = N / 5; // 몫을 저장한다
			break; // 나누어 떨어지면 더 이상 진행하지 않고 while 문 밖으로 나간다
		}
		else { // 5로 나누어 떨어지지 않으면
			cnt_3++; // 일단 3kg 봉지를 채운다
			N -= 3;
		}
	}

	cout << cnt_5 + cnt_3 << '\n';

	return 0;
}