#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> V;

	double n; // 올바른 계산을 위해 n 을 실수 자료형으로!
	cin >> n;

	if (n == 0) { // 의견이 없다면 0을 출력하고 끝
		cout << 0 << '\n';
		return 0; 
	}

	for (int i = 0; i < n; i++) {
		int sc;
		cin >> sc;

		V.push_back(sc);
	}

	sort(V.begin(), V.end()); // 난이도 의견을 오름차순 정렬

	double cut = round(n * 3 / 20); // 위/아래로 몇 개 절사인지 계산

	V.erase(V.begin(), V.begin()+cut); // 위쪽 절사
	V.erase(V.end()-cut, V.end()); // 아래쪽 절사

	double hap = 0;
	for (int i = 0; i < V.size(); i++) {
		hap += V[i];
	}
	double avg = round(hap / V.size());

	cout << avg << '\n';

	return 0;
}