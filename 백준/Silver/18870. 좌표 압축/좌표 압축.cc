#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <set>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> V;
	vector<int> cV;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		V.push_back(n); // 배열에 저장
		cV.push_back(n); // 복사본
	}

	sort(cV.begin(), cV.end()); // 정렬
	cV.erase(unique(cV.begin(), cV.end()), cV.end()); // 중복 제거

	for (int i = 0; i < V.size(); i++) {
		int now = V[i];
		auto it = lower_bound(cV.begin(), cV.end(), now); // lower_bound 함수로 배열의 값 찾기

		cout << it - cV.begin() << " ";
	}
	
	return 0;
}