#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;
	vector<string> S;

	int N, M;
	cin >> N >> M;

	S.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	sort(S.begin(), S.end());

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		if (binary_search(S.begin(), S.end(), s)) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}