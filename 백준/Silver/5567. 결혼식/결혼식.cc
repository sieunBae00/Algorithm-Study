#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> relationship;
vector<bool> visited; // 초대장 전달 여부 표시
vector<int> friends;

int solve1(int root) { // root에 연결된(방문하지않은) 친구 수를 세어 반환
    visited[root] = true;
    int res = 0;
    for (int f : relationship[root]) {
        if (!visited[f]) {
            res++;
            friends.push_back(f);
            visited[f] = true; // 초대장 전달!
        }
    }
    return res;
}

int solve2(int root) {
    int res = 0;
    for (int f : relationship[root]) {
        if (!visited[f]) {
            res++;
            visited[f] = true; // 초대장 전달!
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    relationship.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        relationship[a].push_back(b);
        relationship[b].push_back(a);
    }

    int ans = 0;

    ans += solve1(1);

    for (int f : friends) {
        ans += solve2(f);
    }

    cout << ans << '\n';

    return 0;
}