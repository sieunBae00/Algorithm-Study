#include<iostream>
using namespace std;
#include <stack>

int main()
{
    int ans = 0;
    int K;
    cin >> K;
    
    stack<int> st;
    
    for(int i=0; i<K; i++){
        int n;
        cin >> n;
        
        if(n == 0) st.pop();
        else st.push(n);
    }
    
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    
    cout << ans << endl;
}