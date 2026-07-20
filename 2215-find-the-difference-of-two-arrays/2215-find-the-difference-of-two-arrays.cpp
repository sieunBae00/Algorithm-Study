class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);

        unordered_set<int> set1;
        unordered_set<int> set2;

        for(int i=0; i<nums1.size(); i++) set1.insert(nums1[i]); // nums1 의 원소들을 set1 에 저장 (중복 제거됨)
        for(int i=0; i<nums2.size(); i++) set2.insert(nums2[i]); // nums2 의 원소들을 set2 에 저장 (중복 제거됨)

        for(auto it=set1.begin(); it!=set1.end(); ++it){ // set1 을 순회
            if(set2.find(*it) == set2.end()) ans[0].push_back(*it); // set1 의 원소가 set2 에 없다면 ans[0] 에 추가
        }
        for(auto it=set2.begin(); it!=set2.end(); ++it){ // set2 를 순회
            if(set1.find(*it) == set1.end()) ans[1].push_back(*it); // set2 의 원소가 set1 에 없다면 ans[1] 에 추가
        }

        return ans;
    }
};