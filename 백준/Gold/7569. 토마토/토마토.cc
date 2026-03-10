#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct Point {
    int z, y, x;
};

int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {1, -1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> board(H, vector<vector<int>>(N, vector<int>(M)));
    queue<Point> q;
    int notred = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    q.push({i, j, k});
                } else if (board[i][j][k] == 0) {
                    notred++;
                }
            }
        }
    }

    if (notred == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int days = 0;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = curr.z + dz[i];
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];

            if (nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (board[nz][ny][nx] == 0) {
                    board[nz][ny][nx] = board[curr.z][curr.y][curr.x] + 1;
                    q.push({nz, ny, nx});
                    notred--;
                    days = board[nz][ny][nx] - 1;
                }
            }
        }
    }

    if (notred > 0) {
        cout << -1 << '\n';
    } else {
        cout << days << '\n';
    }

    return 0;
}