class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int, int> map;

        // 모든 경기 결과를 저장
        for(int i=0; i<matches.size(); i++){ 
            int winner = matches[i][0]; // 이긴 선수
            int loser = matches[i][1]; // 진 선수
            if(map.find(winner) == map.end()) map[winner] = 0; // 이긴 선수 -> map 에 존재하지 않았을 경우에만 세팅.
            map[loser]++; // 진 선수 -> 없었다면 (loser, 1) 세팅, 있었다면 원래 있던 값에 +1.
        }

        for(auto it=map.begin(); it!=map.end(); it++){
            if(it->second == 0) ans[0].push_back(it->first); // 한 번도 안 진 선수
            else if(it->second == 1) ans[1].push_back(it->first); // 딱 한 번 진 선수
        }

        return ans;
    }
};