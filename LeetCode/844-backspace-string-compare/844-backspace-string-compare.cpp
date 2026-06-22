class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> st1; // 스택 역할을 할 배열 선언
        vector<char> st2;

        for(char c : s){
            if(c == '#'){
                if(!st1.empty()) st1.pop_back();
                else continue;
            } 
            else st1.push_back(c);
        }

        for(char c : t){
            if(c == '#'){
                if(!st2.empty()) st2.pop_back();
                else continue;
            }             
            else st2.push_back(c);
        }

        if(st1 == st2) return true;
        else return false;
    }
};
