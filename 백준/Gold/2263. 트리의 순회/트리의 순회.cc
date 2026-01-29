#include <iostream>
using namespace std;
#include <vector>

const int MAX = 100001;

int n;
int inorder[MAX];
int postorder[MAX];
int position[MAX]; 

void solve(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;

    int root = postorder[post_end];

    cout << root << " ";

    int root_idx = position[root];

    int left_size = root_idx - in_start;

    solve(in_start, root_idx - 1, post_start, post_start + left_size - 1);

    solve(root_idx + 1, in_end, post_start + left_size, post_end - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    solve(0, n - 1, 0, n - 1);

    return 0;
}