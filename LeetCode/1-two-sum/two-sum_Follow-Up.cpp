class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            auto exist = map.find(target-nums[i]);
            if(exist != map.end()){
                ans.push_back(i);
                ans.push_back(exist->second); // 인덱스를 반환해야 하므로 second 값을 넣는다
            }
            else map.insert({nums[i], i}); // (값, 인덱스) 저장
        }
        return ans;
    }
};
