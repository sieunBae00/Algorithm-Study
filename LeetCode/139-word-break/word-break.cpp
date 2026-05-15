class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> ans;
        ans.resize(s.size()+1, false);

        unordered_set<string> Dictset;
        for(int i=0; i<wordDict.size(); i++){
            Dictset.insert(wordDict[i]);
        }

        ans[0] = true; // 빈 문자열은 무조건 만들 수 있음

        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(ans[j] == true && Dictset.find(s.substr(j, i-j)) != Dictset.end()) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[ans.size()-1];
    }
};