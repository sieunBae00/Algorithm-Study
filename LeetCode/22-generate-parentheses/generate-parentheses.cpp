class Solution {
private:
    vector<string> ans;

    void make_parentheses(string current_str, int open, int close){
        if(open == 0 && close == 0){ // 종결조건
            ans.push_back(current_str);
            return;
        }
        if(open > 0){
            current_str.push_back('('); // 변수의 값 직접 변경
            open--; // 변수의 값 직접 변경
            make_parentheses(current_str, open, close);
            
            // 원상복구
            current_str.pop_back();
            open++;
        }
        if(open < close){
            current_str.push_back(')'); // 변수의 값 직접 변경
            close--; // 변수의 값 직접 변경
            make_parentheses(current_str, open, close);
            
            // 원상복구
            current_str.pop_back();
            close++;
        }
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        make_parentheses("", n, n);
        return ans;
    }
};