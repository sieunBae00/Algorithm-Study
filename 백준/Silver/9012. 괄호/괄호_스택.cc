#include <iostream>
using namespace std;
#include <stack>

int main(){
    int N;
    cin >> N;
    stack<char> st;
    
    for(int i=0; i<N; i++){
        bool success = true;
        while(!st.empty()){
            st.pop();
        }
        
        string s;
        cin >> s;
        
        for(int j=0; j<s.length(); j++){
            char c = s.at(j);
            
            if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                if(st.empty()) {
                    success = false;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }
        
        if((success == true) && st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
