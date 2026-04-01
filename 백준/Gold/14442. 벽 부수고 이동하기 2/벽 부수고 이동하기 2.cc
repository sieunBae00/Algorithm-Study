#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <queue>

int N, M, K;
int map[1000][1000];
int visited[1000][1000][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct State {
    int x, y, k, dist;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    queue<State> q;
    q.push({0, 0, 0, 1});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.x == N - 1 && curr.y == M - 1) {
            cout << curr.dist << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == 0 && !visited[nx][ny][curr.k]) {
                    visited[nx][ny][curr.k] = 1;
                    q.push({nx, ny, curr.k, curr.dist + 1});
                }
                if (map[nx][ny] == 1 && curr.k < K && !visited[nx][ny][curr.k + 1]) {
                    visited[nx][ny][curr.k + 1] = 1;
                    q.push({nx, ny, curr.k + 1, curr.dist + 1});
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}