class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1) return;

        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
        
        return;
    }
};