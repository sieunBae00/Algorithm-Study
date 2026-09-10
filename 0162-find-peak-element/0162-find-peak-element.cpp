class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left(0), right(nums.size()-1);
        int mid;
        
        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] < nums[mid+1]) left = mid+1;
            else right = mid; // mid 본인이 peak 일 수 있으므로 mid-1 이 아닌 mid 로 범위를 좁힌다.
        }
        // left == right == mid 인 상황
        return left;
    }
};