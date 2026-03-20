#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> task;

	int n;
	cin >> n;

	task.resize(n+1);

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		task[i] = a; // 일들의 마감 기한을 저장
	}

	sort(task.begin(), task.end()); // 마감기한이 빠른 순서대로 정렬 (greedy)

	int k = task[1] / 1;

	for (int i = 1; i < task.size(); i++) {
		int curr_k = task[i] / i;
		if (k > curr_k) k = curr_k;
	}

	cout << k << '\n';

	return 0;
}