#include <iostream>
using namespace std;
#include <vector>
#include <cmath> 


int K;
vector<int> building; 
vector<vector<int>> level; 

void decLevel(int start, int end, int depth) {
    if (start > end) return;

    int mid = (start + end) / 2;

    level[depth].push_back(building[mid]);

    decLevel(start, mid - 1, depth + 1);

    decLevel(mid + 1, end, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    int num = pow(2, K) - 1;

    for (int i = 0; i < num; i++) {
        int num;
        cin >> num;
        building.push_back(num);
    }

    level.resize(K);

    decLevel(0, num - 1, 0);

    for (int i = 0; i < K; i++) {
        for (int node : level[i]) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}