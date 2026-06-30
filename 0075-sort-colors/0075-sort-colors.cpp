class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left(0), right(nums.size()-1); // 0, 2 경계 포인터
        int curr(0); // 현재 숫자
        int tmp;

        while(curr <= right){
            if(nums[curr] == 0){ // 0을 만났을 경우
                // curr 와 left 를 swap.
                tmp = nums[left];
                nums[left] = nums[curr];
                nums[curr] = tmp;
                left++;
                curr++;
            }
            else if(nums[curr] == 2){ // 2를 만났을 경우
                // curr 와 right 를 swap.
                tmp = nums[right];
                nums[right] = nums[curr];
                nums[curr] = tmp;
                right--;
            }
            else if(nums[curr] == 1){ // 1을 만났을 경우
                curr++; // 위치 swap 필요 x. curr 만 한 칸 전진
            }
        }
    }
};