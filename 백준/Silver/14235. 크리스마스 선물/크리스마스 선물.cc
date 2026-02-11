#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, less<int>> gift;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == 0) {
			if (!gift.empty()) {
				cout << gift.top() << '\n';
				gift.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}

		for (int j = 0; j < a; j++) {
			int v;
			cin >> v;

			gift.push(v);
		}
	}

	return 0;
}