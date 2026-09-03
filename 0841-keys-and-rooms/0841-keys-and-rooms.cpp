class Solution {
public:
    void DFS(vector<vector<int>>& rooms, int num, vector<bool>& visited){
        visited[num] = true;
        
        for(int k : rooms[num]){
            if(!visited[k]) DFS(rooms, k, visited);
        }
        
        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited;
        visited.resize(rooms.size(), false);
        
        DFS(rooms, 0, visited);
        
        for(bool b : visited){
            if(!b) return false;
        }
        
        return true;
    }
};