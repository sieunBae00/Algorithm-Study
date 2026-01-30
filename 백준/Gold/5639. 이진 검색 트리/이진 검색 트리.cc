#include <iostream>

using namespace std;

int tree[10001];

void solve(int start, int end) {
    if (start >= end) return;
    
    int root = tree[start];
    int split = start + 1;
    
    while (split < end && tree[split] < root) {
        split++;
    }
    
    solve(start + 1, split);
    solve(split, end);
    cout << root << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int val, idx = 0;
    while (cin >> val) {
        tree[idx++] = val;
    }
    
    solve(0, idx);
    
    return 0;
}