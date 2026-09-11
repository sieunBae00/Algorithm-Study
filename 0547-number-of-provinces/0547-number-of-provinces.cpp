class Solution {
public:
    void DFS(int curr, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[curr] = true;

        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[curr][i] == 1 && !visited[i]) DFS(i, isConnected, visited);
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited;
        visited.resize(isConnected.size(), false);
        int ans = 0;

        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]) {
                DFS(i, isConnected, visited);
                ans++;
            }
        }

        return ans;
    }
};