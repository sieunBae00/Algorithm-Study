class Solution {
private:
    vector<string> ans;

    void make_parentheses(string current_str, int open, int close){
        if(open == 0 && close == 0){ // 종결조건
            ans.push_back(current_str);
            return;
        }
        if(open > 0){
            make_parentheses(current_str + "(", open-1, close); // 값을 복사해서 넘겨줌
        }
        if(open < close){
            make_parentheses(current_str + ")", open, close-1); // 값을 복사해서 넘겨줌
        }
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        make_parentheses("", n, n);
        return ans;
    }
};
