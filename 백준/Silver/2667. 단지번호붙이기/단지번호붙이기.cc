#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> ans;

int N;

int dx[4] = { -1, 1, 0, 0 }; // x좌표의 변화 배열 (상, 하, 좌, 우)
int dy[4] = { 0, 0, -1, 1 }; // y좌표의 변화 배열 (상, 하, 좌, 우)

int DFS(int i, int j) {
	visited[i][j] = true; // 방문처리
	int cnt = 1; // 집 한 채 확보
	
	for (int dir = 0; dir < 4; dir++) {
		int next_x = i + dx[dir]; // 다음 x좌표
		int next_y = j + dy[dir]; // 다음 y좌표

		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) { // 다음 x, y 가 배열의 범위를 벗어나지 않는다면
			if (!visited[next_x][next_y] && map[next_x][next_y] == 1) { // 방문x 이고 집이 있다면
				cnt += DFS(next_x, next_y);
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 2차원 배열 초기화
	map.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		map[i].resize(N);
		visited[i].resize(N, false);
	}

	for (int i = 0; i < N; i++) {
		string s; // 띄어쓰기 없는 입력 (문자)
		cin >> s;

		for (int j = 0; j < N; j++) {
			map[i][j] = s[j] - '0'; // 문자('0', '1') 을 숫자(0, 1) 로 바꾸어 저장
		}
	}

	// 방문하지 않은 곳 && 집이 있는 위치 에서 DFS() 탐색 시작
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] == 1) ans.push_back(DFS(i, j));
		}
	}

	cout << ans.size() << '\n'; // 단지의 개수 출력

	sort(ans.begin(), ans.end()); // 정답 배열 정렬
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n'; // 단지 내 집의 수 출력

	return 0;
}