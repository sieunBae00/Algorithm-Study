class Solution {
public:
    int minimumLength(string s) {
        int i(0), j(s.length()-1);

        while(i < j){
            if(s[i] == s[j]){
                char c = s[i];

                while(c == s[i+1] && i<=j) i++;
                while(c == s[j-1] && i<=j) j--;
                
                if(i <= j){
                    i++;
                    j--;
                }
            }
            else break;
        }
        return j-i+1;
    }
};