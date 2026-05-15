class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i(0), j(0);
        int ans = 0;

        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){ // 만족 가능 
                ans++;
                i++;
                j++;
            }
            else{ // 만족 불가능 
                j++; // 쿠키 사이즈 키우기 
            }
        }

        return ans;
    }
};