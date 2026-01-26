// 백준 1991 트리 순회

#include <iostream>
using namespace std;
#include <vector>

vector<pair<int, int>> child;

void inorder(int r) {
    if (child[r].first != 0) inorder(child[r].first);
    cout << (char)(r + 'A');
    if (child[r].second != 0) inorder(child[r].second);
}

void preorder(int r) {
    cout << (char)(r + 'A');
    if (child[r].first != 0) preorder(child[r].first);
    if (child[r].second != 0) preorder(child[r].second);
}

void postorder(int r) {
    if (child[r].first != 0) postorder(child[r].first);
    if (child[r].second != 0) postorder(child[r].second);
    cout << (char)(r + 'A');
}

int main() {
    int N;
    cin >> N;

    child.resize(N);

    for (int i = 0; i < N; i++) {
        char c, l, r;
        cin >> c >> l >> r;

        if (l != '.') child[c - 'A'].first = l - 'A';
        if (r != '.') child[c - 'A'].second = r - 'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;

    return 0;
}