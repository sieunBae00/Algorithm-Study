class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i(0), j(nums.size()-1);
        int tmp = 0;

        while(i < j){
            if((nums[i]%2 != 0) && (nums[j]%2 == 0)){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            if(nums[i]%2 == 0) i++;
            if(nums[j]%2 != 0) j--;
        }
        return nums;
    }
};