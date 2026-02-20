#include <iostream>
using namespace std;
#include<vector>

vector<int> Truth; // 처음부터 진실을 아는 사람들
vector<int> exponent;

int find(int r) {
	if (Truth[r] == r) return r; // boss 가 자기자신이라면 그대로 return

	return find(Truth[r]); // 자기자신이 아닌 boss 라면 재귀
}

void Union(int a, int b) {
	int rootA = find(a); // a의 최종 보스 저장
	int rootB = find(b); // b의 최종 보스 저장

	if (rootA == rootB) return; // 최종 보스가 같다면, 이미 같은 그룹이다
	else if (rootA < rootB) Truth[rootB] = rootA; // 작은 쪽이 boss 가 된다
	else Truth[rootA] = rootB;

	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;

	int N, M; // N: 전체사람 수, M: 파티 수
	cin >> N >> M;

	Truth.resize(N + 1);

	for (int i = 0; i < N + 1; i++) {
		Truth[i] = i;     // boss 를 자기자신으로 초기화
	}

	int T; // (처음) 진실을 아는 사람 수
	cin >> T;
	for (int i = 0; i < T; i++) {
		int t;
		cin >> t;

		Truth[t] = 0; // 진실을 아는 사람들의 boss 를 0번으로 저장
	}

	for (int i = 1; i <= M; i++) { 
		int n;
		cin >> n;

		int exp;
		cin >> exp; // 파티의 대표자 설정
		exponent.push_back(exp); // 나중을 위해 각 파티의 대표자를 저장

		for (int j = 0; j < n-1; j++) { // 같은 파티의 사람들끼리 boss 대결해서 합치기 (Union)
			int p;
			cin >> p;
			Union(exp, p);
		}
	}
	// '진실 그룹' 이 모두 연결된 상태 (루트, 최종보스 는 0)

	for (int i = 0; i < exponent.size(); i++) {
		if (find(exponent[i]) == 0) continue; // 그룹의 최종 보스가 0이라면 거짓말 불가
		else ans++;
	}

	cout << ans << '\n';

	return 0;
}