#include <iostream>
using namespace std;
#include <vector>

vector<int> inorder;
vector<int> postorder;
vector<int> ans;

void solve(int in_start, int in_end, int post_start, int post_end) {
	if ((in_end < in_start) || (post_end < post_start)) return;

	int root = postorder[post_end];
	cout << root << " ";

	int flag;
	for (int i = in_start; i <= in_end; i++) {
		if (inorder[i] == root) {
			flag = i;
			break;
		}
	}

	int L_size = (flag - 1) - in_start + 1;
	int R_size = in_end - (flag + 1);


	solve(in_start, flag - 1, post_start, post_start + L_size - 1);
	solve(flag + 1, in_end, post_start + L_size, post_start + L_size + 1 + R_size - 1);

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	inorder.resize(n + 1);
	postorder.resize(n + 1);


	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		inorder[i] = num;
	}

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		postorder[i] = num;
	}

	solve(1, n, 1, n);

	return 0;
}
