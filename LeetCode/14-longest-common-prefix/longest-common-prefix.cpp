class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ref = strs[0]; // 0번째 문자열을 기준으로 

        for (int i = 0; i < ref.size(); i++) {
            char current_char = ref[i]; // 현재 검사할 글자 

            for (int j = 1; j < strs.size(); j++) {
                
                // 조건 1: 비교할 단어의 길이가 i보다 짧을 때
                // 조건 2: 글자가 서로 다를 때
                if ( strs[j].size() < i || current_char != strs[j][i] ) {
                    return ref.substr(0, i); // 단어의 (처음)~(현재 위치 직전)까지 잘라서 반환
                }
            }
        }

        return ref;
    }
};