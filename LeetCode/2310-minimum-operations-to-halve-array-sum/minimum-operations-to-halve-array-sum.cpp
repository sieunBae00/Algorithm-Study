class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end()); // 우선순위큐 선언. 자료형 주의 
        double red = 0; // 줄어든 양
        double hap = 0;
        int ans = 0; // 연산 횟수

        for(int i=0; i<nums.size(); i++) hap += nums[i]; // 배열 전체의 합 계산

        while(red < hap/2){
            double n = pq.top();
            pq.pop();
            red += n/2;

            pq.push(n/2);
            ans++;
        }
        
        return ans;
    }
};