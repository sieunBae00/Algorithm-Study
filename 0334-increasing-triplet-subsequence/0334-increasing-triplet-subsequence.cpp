class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX; // 큰 수로 초기화하고 시작
        int second = INT_MAX;

        for(int n : nums){
            if(n < first) first = n;
            else if(n > first && n < second) second = n;
            else if(n > second) return true;
        }

        return false;
    }
};