class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest(0), altitude(0);

        for(int i=0; i<gain.size(); i++){
            altitude += gain[i]; // 현재 고도 업데이트(누적합)
            if(altitude > highest) highest = altitude; // 최대 고도 갱신
        }

        return highest; // 최대 고도 반환
    }
};