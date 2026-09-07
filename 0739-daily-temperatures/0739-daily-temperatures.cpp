class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        ans.resize(temperatures.size());

        stack<int> st;

        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i); // '오늘' 도 기온이 더 높은 날을 찾아야 함
        }

        while(!st.empty()){ // 순회 후에도 스택에 남아 있는 경우 -> 기온이 더 높은 날을 찾지 못함
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
    }
};