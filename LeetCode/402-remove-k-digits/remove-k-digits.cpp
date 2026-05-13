class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = ""; // string 을 스택처럼 활용하기

        for(char c : num){
            while(!ans.empty() && ans.back() > c && k > 0){ // 비어있지 않고, top() 이 더 크고, k가 남았다면
                ans.pop_back();
                k--;
            }
            if(ans.empty() && c == '0') continue; // 맨 앞 자리 0은 처음부터 넣지 않음 

            ans.push_back(c);
        }

        // 예외 케이스 : 12345 와 같이 뒤에 오는 숫자가 항상 더 클 경우
        if(k > 0){
            while(!ans.empty() && k > 0){
                ans.pop_back(); // 뒤에서부터 k번 지우기
                k--;
            }
        }
        return (ans.empty()) ? "0" : ans; // ans 가 비었다면 0 반환하기 

    }
};