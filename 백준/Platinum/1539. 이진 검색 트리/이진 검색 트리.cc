#include <iostream>
using namespace std;
#include<set>
#include<algorithm>
#include<vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> P;
	vector<int> depth;

	int N;
	cin >> N;

	depth.resize(N);

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;

		int large_d = -1;
		int small_d = -1;

		auto now = P.insert(p);
		auto n = now.first;

		auto n_plus = n;
		auto n_minus = n;

		n_plus++; // 연산자 오버로딩

		if (n_plus != P.end()) {
			large_d = depth[*n_plus]; // 역참조
		}
		else large_d = 0;

		if (n != P.begin()) {
			n_minus--; // 연산자 오버로딩
			small_d = depth[*n_minus]; // 역참조
		}
		else small_d = 0;


		int now_d = max(large_d, small_d);
		depth[p] = now_d + 1;
	}

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += depth[i];
	}

	cout << ans << '\n';
}