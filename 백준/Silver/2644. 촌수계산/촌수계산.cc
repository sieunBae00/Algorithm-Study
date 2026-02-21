#include <iostream>
using namespace std;
#include<vector>

vector<vector<int>> family;
vector<bool> visited;

int findFamily(int st, int end, int ans) {
	visited[st] = true;

	if (st == end) {
		return ans; // 올바른 길 찾음
	}

	for (int next : family[st]) {
		if (!visited[next]) {
			int res = findFamily(next, end, ans+1);
			if (res != -1) return res; //부하가 올바른 길을 찾았다면(-1 아닌 것 확인), 다른 길 살펴볼 필요 없이 상사에게 보고
		}
	}

	return -1; // 아무리 해도 올바른 길 못 찾음
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	family.resize(n + 1);
	visited.resize(n + 1, false);

	int st, end;
	cin >> st >> end;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		family[x].push_back(y);
		family[y].push_back(x);
	}

	cout << findFamily(st, end, 0) << '\n';

	return 0;
}
