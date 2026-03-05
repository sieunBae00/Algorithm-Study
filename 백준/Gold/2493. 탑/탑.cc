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

    for (int i = N - 1; i >= 0; i--) {
      
        while (!st.empty() && v[st.top()-1] < v[i]) {
            ans[st.top()-1] = i + 1;
            st.pop();
        }

        if (st.empty() || v[st.top() - 1] > v[i]) {
            st.push(i + 1);
            continue;
        }
    }

    while (!st.empty()) {
        ans[st.top()-1] = 0;
        st.pop();
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
