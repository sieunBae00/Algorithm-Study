class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> pq;
        for(int i : stones) pq.push(i);

        int s1, s2;
        while(pq.size()>1){
            s1 = pq.top();
            pq.pop();
            s2 = pq.top();
            pq.pop();

            if(s1 != s2) pq.push(abs(s1-s2));
        }

        if(pq.empty()) return 0;
        else return pq.top();
    }
};