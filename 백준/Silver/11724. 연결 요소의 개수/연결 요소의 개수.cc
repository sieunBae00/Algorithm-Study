#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int curr){
    visited[curr] = true;
    for(int next : graph[curr]){
        if(!visited[next]) DFS(next);
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0; // 연결요소 슈
    
    int N, M;
    cin >> N >> M;
    
    graph.resize(N+1);
    visited.resize(N+1, false);
    
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for(int i=1; i<=N; i++){
        if(!visited[i]) {
            DFS(i);
            ans++;
        }
    }
    
    cout << ans << '\n';
    
   return 0;
}