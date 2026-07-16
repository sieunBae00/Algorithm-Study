class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ps(0), pt(0);

        while(1){
            if(ps > s.size()) return true; // s 의 끝까지 도달하면 -> 성공
            if(pt > t.size()) return false; // t 의 끝까지 도달하면 -> 실패

            if(s[ps] == t[pt]){
                ps++;
                pt++;
            }
            else pt++;
        }
    }
};