#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

void hanoi(int n, int st, int end, int mid) { // (원판 개수, 출발지, 도착지, 보조기둥)
	if (n == 1) { // 이동시킬 원판이 1개뿐이라면
		cout << st << " " << end << '\n';   // 바로 출발->도착 으로 옯기고 끝!
		return;
	}
	else { // 이동시킬 원판이 2개 이상이라면
		hanoi(n - 1, st, mid, end); // 맨 밑 원판 기준 st->end 로 가야 하므로, 먼저 그 위의 원판들을 st->mid 로 옮겨야 한다.

		cout << st << " " << end << '\n'; // 맨 밑에 깔린 원판 이동(st->end)

		hanoi(n - 1, mid, end, st); // 다시 맨 밑을 제외한 나머지 원판들을 위로 가져오기(mid->end)
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int K = pow(2, N) - 1; // 옮기는 횟수
	cout << K << '\n'; 

	hanoi(N, 1, 3, 2); // 문제 상황 그대로를 전달

	return 0;
}