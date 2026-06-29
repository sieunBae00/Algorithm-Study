class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set;

        for(int i=0; i<nums.size(); i++){
            set.insert(nums[i]); // 배열의 요소를 set 에 저장
        }

        for(int i=0; i<= nums.size(); i++){
            if(set.find(i) == set.end()) return i; // set 에 없는 값을 반환
        }

        return -1;
    }
};