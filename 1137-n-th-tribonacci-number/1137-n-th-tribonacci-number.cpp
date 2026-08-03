class Solution {
public:
    int tribonacci(int n) {
        vector<int> nums(38);
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 1;
        
        for(int i=3; i<nums.size(); i++){
            nums[i] = nums[i-3] + nums[i-2] + nums[i-1];
        }
        
        return nums[n];
    }
};