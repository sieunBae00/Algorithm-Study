#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> card;

    int N;
    cin >> N;

    card.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }

    sort(card.begin(), card.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int m;
        cin >> m;

        cout << upper_bound(card.begin(), card.end(), m) - lower_bound(card.begin(), card.end(), m) << " ";
    }

    return 0;
}