class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.resize(n+1, 0);

        for(int i=1; i<ans.size(); i++){
            ans[i] = (i%2 == 0) ? ans[i/2] : ans[i/2]+1;
        }

        return ans;
    }
};