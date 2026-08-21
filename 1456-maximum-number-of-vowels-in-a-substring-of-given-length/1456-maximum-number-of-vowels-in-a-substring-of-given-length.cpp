class Solution {
public:
    int maxVowels(string s, int k) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max = 0;

        for(int i=0; i<k; i++){
            auto it = find(vowels.begin(), vowels.end(), s[i]);
            if(it != vowels.end()) max++;
        }

        int curr = max;
        for(int i=0; i<=s.size()-k; i++){
            
            auto it = find(vowels.begin(), vowels.end(), s[i]);
            if(it != vowels.end()) curr--;

            it = find(vowels.begin(), vowels.end(), s[i+k]);
            if(it != vowels.end()) curr++;

            if(curr > max) max = curr;
        }

        return max;
    }
};