class Solution {
public:
    bool ifPossible(vector<int>& piles, int h, int k){
        int time = 0;
        for(int p : piles){
            if((double)p / k == p / k) time += p / k;
            else time += p / k + 1;
        }

        return (time <= h) ? true : false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int min(1), max(0);

        for(int p : piles){
            if(p > max) max = p;
        }

        int mid;
        while(min < max){
            mid = (min + max) / 2;

            if(ifPossible(piles, h, mid)) max = mid;
            else min = mid + 1;
        }
        return (min > max) ? max : min;
    }
};