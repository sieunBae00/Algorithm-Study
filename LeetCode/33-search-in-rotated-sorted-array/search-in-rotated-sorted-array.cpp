class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;

        while(left <= right){
            mid = (left + right) / 2;

            if(nums[mid] == target) return mid;

            if(nums[left] <= nums[mid]){ // 왼쪽이 정렬된 경우 
                if(target <= nums[mid] && target >= nums[left]){ // 왼쪽 범위에 target 이 존재한다면
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            else{ // 오른쪽이 정렬된 경우
                if(target <= nums[right] && target >= nums[mid]){ // 오른쪽 범위에 target 이 존재한다면
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }

        return -1;
    }
};