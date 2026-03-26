#include <iostream>
using namespace std;
#include <queue>
#include <cmath>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int t = 1; // 1단계부터 시작

	while (!(q.size() == 1)) {
		// t^3 이 q.size() 보다 크면 한 바뀌 도는 것은 의미없으므로 나머지를 계산
		long long remain = ((long long)pow(t, 3)-1) % q.size(); // 탈락자 = t^3 번째 사람 -> t^3-1 번 뒤로 넘기기

		for (int i = 0; i < remain; i++) {
			int a = q.front();
			q.pop();
			q.push(a);
		}
		q.pop(); // 게임에서 제외되는 사람
		t++; // 단계 + 1
	}

	cout << q.front() << '\n';

	return 0;
}