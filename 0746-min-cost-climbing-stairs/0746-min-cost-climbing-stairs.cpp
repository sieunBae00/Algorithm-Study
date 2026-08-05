class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minimumCost(cost.size());

        minimumCost[0] = cost[0];
        minimumCost[1] = cost[1];

        for(int i=2; i<minimumCost.size(); i++){
            minimumCost[i] = min(minimumCost[i-2], minimumCost[i-1]) + cost[i];
        }

        return min(minimumCost[minimumCost.size()-2], minimumCost[minimumCost.size()-1]);
    }
};