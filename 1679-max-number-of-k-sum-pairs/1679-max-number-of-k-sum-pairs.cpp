class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        int min(0), max(nums.size()-1);

        while(min < max){
            if(nums[min] + nums[max] == k){
                ans++;
                min++;
                max--;
            }
            else if(nums[min] + nums[max] < k) min++;
            else max--;
        }

        return ans;
    }
};