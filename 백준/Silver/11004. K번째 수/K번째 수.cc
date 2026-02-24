#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> V;

	int N, k;
	cin >> N >> k;

	for (int i = 0; i < N; i++) {
		int v;
		cin >> v;
		V.push_back(v);
	}

	sort(V.begin(), V.end());

	cout << V[k - 1] << '\n';

	return 0;
}