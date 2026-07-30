class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size()); // 정답 배열 선언

        int max_kid = 0;
        for(int i=0; i<candies.size(); i++){
            if(candies[i] > max_kid) max_kid = candies[i]; // 가장 많은 사탕의 개수 저장
        }

        max_kid -= extraCandies; // 가장 많은 사탕과의 개수 차이

        for(int i=0; i<candies.size(); i++){
            if(candies[i] >= max_kid) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }
};