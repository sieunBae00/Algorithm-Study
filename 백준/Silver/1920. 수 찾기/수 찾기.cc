#include <iostream>
using namespace std;
#include <set>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> bst;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		bst.insert(a);
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int m;
		cin >> m;

		if (bst.find(m) == bst.end()) cout << 0 << '\n';
		else cout << 1 << '\n';
	}

	return 0;
}