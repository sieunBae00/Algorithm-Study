class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '{' || c == '[') st.push(c); // 여는 괄호: 스택에 push
            else{ // 닫는 괄호
                if(st.empty()) return false;
                
                // 짝이 맞을 경우 스택에서 여는 괄호를 pop
                if(c == ')' && st.top() == '(') st.pop();
                else if(c == '}' && st.top() == '{') st.pop();
                else if(c == ']' && st.top() == '[') st.pop();
                else return false;
            }
        }

        if(!st.empty()) return false; // 스택이 비어있지 않으면 짝이 안 맞음
        else return true;
    }
};