class Solution {
public:
    string reverseWords(string s) {
        s += " "; // 예외 처리를 위해 맨 뒤에 공백을 추가.

        string str = "";
        string ans = "";

        for (char c : s){
            if(c == ' ') {
                if(str.size() != 0){
                    ans = str + " " + ans; // 앞쪽에 새로운 단어를 이어 붙이기(reverse)
                    str = "";
                }
                else continue;
            }
            else str += c;
        }

        ans.pop_back(); // 마지막 공백 제거
        return ans;
    }
};