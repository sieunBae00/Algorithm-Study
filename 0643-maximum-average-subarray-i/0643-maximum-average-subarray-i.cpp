class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max(0), curr_sum(0);
        for(int i=0; i<k; i++) curr_sum += nums[i];
        max = curr_sum;

        int cnt = 0;
        while(cnt+k < nums.size()){
            curr_sum = curr_sum - nums[cnt] + nums[cnt+k];
            if(max < curr_sum) max = curr_sum;
            cnt++;
        }

        return max / k;
    }
};