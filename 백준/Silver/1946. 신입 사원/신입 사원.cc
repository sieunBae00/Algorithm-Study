#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<pair<int, int>> V;
		int fail_num = 0;

		int N;
		cin >> N;

		for (int j = 0; j < N; j++) {
			int x, y;
			cin >> x >> y;

			V.push_back({ x, y }); //(서류등수, 면접등수)
		}

		sort(V.begin(), V.end()); // 서류등수 순으로 정렬

		int pre_rank = V[0].second; // 서류점수가 1등인 지원자의 면접등수 저장

		for (int j = 1; j < V.size(); j++) { // 배열의 앞 -> 뒤 로 돌면서 (어차피 서류 2등부터는 서류로 승부 보기는 틀렸음)
			if (V[j].second < pre_rank) pre_rank = V[j].second; // 앞에서 내려온 pre_rank 와 자신의 rank 를 비교한다. 
			else fail_num++; // 거기서도 졌다면, 가망 없음 -> 탈락자 수 + 1
		}

		cout << N - fail_num << '\n';
	}

	return 0;
}