class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 오름차순 정렬
        int ans = 0;

        int min = nums[0];
        for(int i=1; i<nums.size(); i++){
            ans += nums[i] - min;
        }

        return ans;
    }
};