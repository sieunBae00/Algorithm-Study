class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product1(nums.size());
        vector<int> product2(nums.size());
        vector<int> ans(nums.size());
        int prod1(1), prod2(1);

        for(int i=0; i<product1.size(); i++){ // 정방향 누적곱 계산
            prod1 *= nums[i];
            product1[i] = prod1;
        }

        for(int i=product2.size()-1; i>=0; i--){ // 역방향 누적곱 계산
            prod2 *= nums[i];
            product2[i] = prod2;
        }

        for(int i=0; i<ans.size(); i++){
            if(i == 0) ans[i] = product2[i+1];
            else if(i == ans.size()-1) ans[i] = product1[i-1];
            else ans[i] = product1[i-1] * product2[i+1];
        }

        return ans;
    }
};