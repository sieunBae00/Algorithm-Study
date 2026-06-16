class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast=0; fast<nums.size(); fast++){ //fast 는 무조건 전진하며 순회
            if(nums[fast] != val){ // 전진하다 만난 숫자가 유효한 숫자라면
                nums[slow] = nums[fast]; // 앞쪽에 덮어씌우기
                slow++; // 덮어씌운 후 전진
            }
        }
        return slow; // 덮어씌운 횟수 = 유효한 숫자 개수
    }
};