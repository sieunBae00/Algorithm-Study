#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int, vector<int>, less<int>> pq;
    
    int N;
    cin >> N;
    
    int vote_d;
    cin >> vote_d; // 다솜이(1번) 의 득표수
    
    for(int i=2; i<=N; i++){
        int n;
        cin >> n;
        
        pq.push(n); // 나머지 후보들의 득표수 저장(내림차순)
    }
    
    int ans = 0; // 매수한 사람 수
    
    while(!pq.empty() && (pq.top() >= vote_d)){ // 다솜이가 1등이 아닐 경우
        int contend = pq.top();
        pq.pop();
        contend--;
        vote_d++;
        ans++;
        pq.push(contend);
    }
    
    cout << ans << '\n';
    
   return 0;
}