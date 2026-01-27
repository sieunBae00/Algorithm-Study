#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> building;

	int K;
	cin >> K;

	building.resize(pow(2, K));

	for (int i = 1; i < pow(2, K); i++) {
		cin >> building[i];
	}

	for (int i = K; i >= 1; i--) {
		int a = 1 * pow(2, i - 1);
		int d = 2 * pow(2, i - 1);

		vector<int> ans;

		for (int idx = 1; idx <= building.size(); idx++) {
			if ((idx + a) % d == 0) ans.push_back(building[idx]);
		}

		for (int j = 0; j < ans.size(); j++) {
			if (j == ans.size()-1) cout << ans[j] << '\n';
			else cout << ans[j] << " ";
		}
	}
}