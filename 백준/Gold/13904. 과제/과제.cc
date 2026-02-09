#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	typedef pair<int, int> p;

	priority_queue<p, vector<p>, less<p>> pq;
	vector<int> ans;

	int N;
	cin >> N;

	ans.resize(1001, 0);

	for (int i = 0; i < N; i++) {
		int dl, sc;
		cin >> dl >> sc;

		pq.push({ sc, dl });
	}

	while (!pq.empty()) {
		p hw = pq.top();
		pq.pop();

		if (ans[hw.second] == 0) {
			ans[hw.second] = hw.first;
		}

		else {
			for (int i = hw.second - 1; i > 0; i--) {
				if (ans[i] == 0) {
					ans[i] = hw.first;
					break;
				}
			}
		}
	}

	int score = 0;

	for (int i = 1; i < ans.size(); i++) {
		score += ans[i];
	}

	cout << score << '\n';
    
    return 0;
}