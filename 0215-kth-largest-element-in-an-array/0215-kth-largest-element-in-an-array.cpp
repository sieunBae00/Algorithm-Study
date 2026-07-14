class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop(); // 가장 작은 수를 pop() -> 가장 큰 수 k 개 남음
        }

        return pq.top();
    }
};