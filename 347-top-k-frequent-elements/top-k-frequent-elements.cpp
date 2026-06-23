class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        vector<int> ans;

        for(int n : nums) map[n]++; // map 에 n 이 없으면 새로 만들고 1을 세팅(초기값 0), n 이 있으면 +1

        for(pair<int, int> v : map) pq.push({v.second, v.first}); // (등장 횟수, 숫자)

        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().second); // 숫자
            pq.pop();
        }
        return ans;
    }
};