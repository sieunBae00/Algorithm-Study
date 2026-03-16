#include <iostream>
using namespace std;
#include <deque>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (!dq.empty() && dq.front().second <= i - L) {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().first >= num) {
            dq.pop_back();
        }

        dq.push_back({num, i});

        cout << dq.front().first << " ";
    }
    cout << '\n';

    return 0;
}