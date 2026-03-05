#include <iostream>
using namespace std;
#include <stack>
#include <vector>

int main() {
    int N;
    stack<int> st;

    cin >> N;
    vector<int> v(N);
    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        if (st.empty()) st.push(i);
        else if (v[st.top()] < v[i]) {
            ans[st.top()] = v[i];
            st.pop();
            i--;
            //continue;
        }
        else st.push(i);
    }

    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}