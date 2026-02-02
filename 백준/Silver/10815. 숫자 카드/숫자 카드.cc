#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> card;

	int N;
	cin >> N;

	card.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int m;
		cin >> m;

		if (i == M) {
			cout << (int)binary_search(card.begin(), card.end(), m);
			return 0;
		}

		cout << (int)binary_search(card.begin(), card.end(), m) << " ";
	}

	return 0;
}