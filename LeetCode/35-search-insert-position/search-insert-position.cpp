class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int min(0), max(nums.size()-1);
        int mid;

        while(min <= max){
            mid = (min + max) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) max = mid - 1;
            else min = mid + 1;
        }
        return (nums[mid] > target) ? mid : mid+1;
    }
};