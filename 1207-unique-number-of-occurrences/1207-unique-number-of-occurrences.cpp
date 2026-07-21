class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        
        for(int i=0; i<arr.size(); i++){ // map 에 {숫자, 개수} 저장
            if(map.find(arr[i]) == map.end()) map.insert({arr[i], 1});
            else map[arr[i]]++;
        }
        
        for(const auto& it : map){
            set.insert(it.second); // set 에 저장 -> 중복 제거
        }
        
        if(map.size() == set.size()) return true; // 중복 제거된 크기가 원래의 크기와 같아야 true
        else return false;
    }
};