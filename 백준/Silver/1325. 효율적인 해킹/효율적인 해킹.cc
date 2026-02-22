#include <iostream>
using namespace std;
#include<vector>

vector<vector<int>> Trust;
vector<int> visited;
vector<int> ans;

int DFS(int root, int ans) {
	visited[root] = true;
	int count = 1;

	for (int next : Trust[root]) {
		if (!visited[next]) {
			count += DFS(next, ans+1);
		}
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max_hack = 0;

	int N, M;
	cin >> N >> M;
	
	Trust.resize(N + 1);
	visited.resize(N + 1);
	ans.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		Trust[b].push_back(a); // 방향 그래프
	}

	for (int i = 1; i <= N; i++) {
		ans[i] = DFS(i, 0);
		if (ans[i] > max_hack) max_hack = ans[i];

		visited.assign(N + 1, false);
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i] == max_hack) cout << i << " ";
	}


	return 0;
}