#include<iostream>
using namespace std;
#include <stack>
#include <vector>

int main()
{
    stack<pair<int, int>> st;
    vector<int> ans;
    
    int N;
    cin >> N;
    
    ans.resize(N+1);
    
    for(int i=1; i<=N; i++){
        int h;
        cin >> h;
        
        // 스택이 비어있지 않은 경우
        while(!st.empty() && st.top().second <= h){ // 높이가 같아도 수신 못함!
            st.pop();
        }
        
        // 수신 못하는 탑들을 pop() 했더니 스택이 빈 경우
        if(st.empty()) { 
            ans[i] = 0;
            st.push({i, h}); // {인덱스, 높이}
            continue;
        }
        
        // 이제 스택의 top() 에는 나보다 큰 탑이 있음
        ans[i] = st.top().first;
        st.push({i, h});
    }
    
    
    for(int i=1; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}
