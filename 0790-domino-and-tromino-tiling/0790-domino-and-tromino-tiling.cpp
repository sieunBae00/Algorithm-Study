class Solution {
public:
    int numTilings(int n) {
        if(n == 1) return 1;
        
        vector<long long> jagged;
        vector<long long> full;
        jagged.resize(n+1, 0);
        full.resize(n+1, 0);
        
        full[1] = 1;
        full[2] = 2;
        jagged[1] = 0;
        jagged[2] = 2;
        
        for(int i=3; i<=n; i++){
            full[i] = (full[i-1] + full[i-2] + jagged[i-1]) % 1000000007;
            jagged[i] = (full[i-2]*2 + jagged[i-1]) % 1000000007;
        }
        
        return full[n];
    }
};