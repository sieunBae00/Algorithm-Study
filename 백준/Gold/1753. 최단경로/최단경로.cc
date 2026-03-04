// 1753 최단경로

#include<iostream>
using namespace std;
#include <vector>
#include <queue>

typedef pair<int, int> edge;

vector<vector<edge>> graph;
vector<bool> visited;

int V, E;
const int INF = 10000000; // 거리 배열 초기화에 사용할 충분히 큰 수 

vector<int> dijkstra(int st){
    vector<int> ans;
    ans.resize(V+1);
    fill(ans.begin(), ans.end(), INF); // 거리 배열 초기화
    fill(visited.begin(), visited.end(), false); // 방문 배열 초기화
    
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    
    ans[st] = 0;
    pq.push({0, st}); // {가중치, 노드}
    
    while(!pq.empty()){
        edge e = pq.top();
        pq.pop();
        int n = e.second; // 노드
        
        if(visited[n]) continue;
        
        visited[n] = true;
        
        for(edge ee : graph[n]){ // {노드, 가중치}
            int next = ee.first;
            int w = ee.second;
            
            if(ans[next] > ans[n] + w){
                ans[next] = ans[n] + w;
                
                pq.push({ans[next], next}); // {가중치, 노드}
            }
        }
    }
    
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> V >> E;
    
    graph.resize(V+1);
    visited.resize(V+1);
    
    int K;
    cin >> K;
    
    for(int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u].push_back({v, w});
    }
    
    vector<int> ans = dijkstra(K);
    
    for(int i=1; i<V+1; i++){
        if(ans[i] >= INF) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
    
    return 0;
}