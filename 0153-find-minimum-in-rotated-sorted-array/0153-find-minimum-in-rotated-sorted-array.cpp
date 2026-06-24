class Solution {
public:
    int findMin(vector<int>& nums) {
        int min(0), max(nums.size()-1);
        int mid = (min + max) / 2;
        
        // 양쪽 다 정상이면 -> rotated n times = 원본 sorted array
        if(nums[min] < nums[mid] && nums[mid] < nums[max]) return nums[min]; 

        while(min < max){
            mid = (min + max) / 2;
            if(nums[mid] > nums[max]) min = mid + 1; // 오른쪽이 비정상 -> 오른쪽으로 범위 좁히기
            else max = mid; // 왼쪽이 비정상 -> 왼쪽으로 범위 좁히기
        }
        return nums[min];
    }
};