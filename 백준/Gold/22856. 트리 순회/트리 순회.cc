#include <iostream>
using namespace std;
#include <vector>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> tree; // 트리 자식 저장 배열

	int N;
	cin >> N;

	tree.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		tree[a].first = b; // 왼쪽 자식
		tree[a].second = c; // 오른쪽 자식
	}

	int root = 1;
	int rightnum = 0;
	while (true) {
		if (tree[root].second != -1) { // 오른쪽 자식이 존재한다면
			root = tree[root].second; // 계속 내려가기
			rightnum++;
		}
		else break; // 오른쪽 자식이 존재하지 않으면 break
	}

	int edge = N - 1; // 트리의 간선 수 = 노드 수 - 1

	cout << edge * 2 - rightnum << '\n';

	return 0;
}