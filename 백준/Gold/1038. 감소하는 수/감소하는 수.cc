#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<long long> V;

void make_num(long long curr) {
	V.push_back(curr); // 일단 들어온 수를 배열에 저장하기

	int last = curr % 10; // 마지막 자리 숫자

	for (int j = 0; j < last; j++) { // 마지막 자리 숫자보다 하나 작은 수까지! (마지막 자리 숫자가 0이면 자동으로 돌지 않는다)
		make_num(curr * 10 + j);
	}
	return;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		make_num(i);
	}

	sort(V.begin(), V.end()); // 배열에 저장된 감소하는 수 정렬하기

	if (N >= V.size()) cout << -1 << '\n';
	else cout << V[N] << '\n';

	return 0;
}