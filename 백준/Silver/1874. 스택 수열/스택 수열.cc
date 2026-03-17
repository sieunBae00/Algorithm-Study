#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> st;
	vector<string> ans;

	int curr = 1; // 스택에 수를 넣을 때마다 +1 증가

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int nn;
		cin >> nn;

		// 일단 스택에 넣기
		while(curr <= nn) {
			st.push(curr);
			curr++;
			ans.push_back("+");
		}
		//넣은 후에는 pop() 하려는 값이 스택의 top() 에 있어야 함

		// 있는 경우: 정상
		if (nn == st.top()) {
			st.pop();
			ans.push_back("-");
		}
		// 없는 경우: 비정상, 수열 만들기 불가능
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}