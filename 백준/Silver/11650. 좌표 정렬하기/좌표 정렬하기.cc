#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> V;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		V.push_back({ x, y });
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < V.size(); i++) {
		cout << V[i].first << " ";
		cout << V[i].second << "\n";
	}

	return 0;
}