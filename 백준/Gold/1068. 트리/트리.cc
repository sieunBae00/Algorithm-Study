#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> child;
vector<int> isDelete;
vector<int> parent;

void deleteNode(int D) {
	isDelete[D] = true;

	if (child[D].size() == 0) return;
	for (int n : child[D]) deleteNode(n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;

	int N;
	cin >> N;

	child.resize(N);
	isDelete.resize(N, false);
	parent.resize(N);

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p; // 부모

		if (p == -1) continue;

		parent[i] = p;
		child[p].push_back(i);
	}

	int D;
	cin >> D;

	if (parent[D] == -1) { // 삭제하려는 노드가 루트 노드이면 0 출력하고 끝. (+ 밑에서 child[-1]에 접근하는 것 방지)
		cout << 0 << '\n';
		return 0;
	}

	deleteNode(D);

	for (int i = 0; i < N; i++) {
		if (isDelete[i]) child[i].clear();
	}

	for (int i = 0; i < N; i++) {
		if (isDelete[i]) continue; // 삭제되었으면 아예 리프 노드 카운팅에서 제외해야 한다.!

		if (child[i].size() == 0) ans++;
	}

	if (child[parent[D]].size() == 1) ans++; // 삭제하려는 노드의 부모 노드의 원래 자식이 1이라면 -> 삭제 후, 부모 노드는 리프 노드가 된다. 따라서 리프노드수 +1

	cout << ans << '\n';


}
