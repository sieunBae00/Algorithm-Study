class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int curr = 0;

        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0 && n < 2) return true;
            else if(flowerbed[0] == 1 && n < 1) return true;
            return false;
        }

        if(flowerbed[0] == 0 && flowerbed[1] == 0) { // 첫 번째 원소
            flowerbed[0] = 1;
            curr++;
        }

        for(int i=1; i<flowerbed.size()-1; i++){ // 양끝 원소를 제외한 나머지 원소
            if(flowerbed[i] == 1) continue;
            else if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                curr++;
            }
        }

        if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0) curr++; // 마지막 원소

        return (curr >= n) ? true : false;
    }
};