#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int root){
    visited[root] = true;
    
    for(int next=1; next<graph[root].size(); next++){
        if(graph[root][next] == 1 && !visited[next]){
            DFS(next);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string ans = "YES";
    
    vector<int> trip;
    
    int N, M;
    cin >> N >> M;
    
    // 2차원 배열을 resize
    graph.resize(N+1);
    for(int i=0; i<N+1; i++){
        graph[i].resize(N+1);
    }
    
    visited.resize(N+1, false);
    trip.resize(M);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> graph[i][j];
        }
    }
    
    for(int i=0; i<M; i++){
        cin >> trip[i];
    }
    
    // 특정 도시에서 시작하여 여행 경로에 포함된 모든 도시에 방문할 수 있어야 함.
    DFS(trip[0]); 
    
    for(int i=0; i<trip.size(); i++){
        if(!visited[trip[i]]){
            ans = "NO";
            break;
        }
    }
    
    cout << ans << '\n';
    
   return 0;
}