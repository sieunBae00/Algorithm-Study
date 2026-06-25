class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;

        // 모든 subarray 순회하기
        for(int i=0; i<nums.size(); i++){
            int cnt = 0; // i 마다 count 초기화 
            for(int j=i; j<nums.size(); j++){
                if(nums[j] == target) cnt++; // 지나가면서 카운트!
                if(2 * cnt > (j - i + 1)) ans++;
            }
        }
        return ans;
    }
};