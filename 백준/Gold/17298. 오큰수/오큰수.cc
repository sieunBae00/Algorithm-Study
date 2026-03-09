#include <iostream>
using namespace std;
#include <stack>
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> V;
	stack<int> st;
	vector<int> ans;

	int N;
	cin >> N;

	V.resize(N);
	ans.resize(N);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		V[i] = a; // 입력되는 수열을 벡터에 저장
	}

	for (int i = N-1; i >= 0; i--) {
		int num = V[i];

		// 스택이 비어있지 않을 때
		while (!st.empty() && st.top() <= num) {
			st.pop();
		}

		// pop() 이후 스택이 비었다면
		if (st.empty()) {
			ans[i] = -1;
			st.push(num);
			continue;
		}

		// 스택에 수가 남아있을 때 = 오큰수 존재
		ans[i] = st.top();
		st.push(num);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}