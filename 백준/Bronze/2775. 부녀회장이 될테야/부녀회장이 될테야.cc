#include <iostream>
using namespace std;
#include <vector>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> apt;
    apt.resize(15);
    for (int i = 0; i <= 14; i++) {
        apt[i].resize(15);
    }

    int T;
    cin >> T;

    for (int i = 1; i <= 14; i++) {
        apt[0][i] = i; // 0층의 i호에는 i명이 산다
    }

    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            for (int k = 1; k <= j; k++) {
                apt[i][j] += apt[i - 1][k];
            }
        }
    }

    for (int i = 0; i < T; i++) {
        int k, n;
        cin >> k >> n;

        cout << apt[k][n] << '\n';
    }

    return 0;
}