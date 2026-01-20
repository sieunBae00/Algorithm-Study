#include <iostream>
using namespace std;
#include <queue>

int main(){
    queue<int> q;
    
    int N, K;
    cin >> N >> K;
    
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    
    cout << '<';
    
    while(!q.empty()){
        for(int i=0; i<K-1; i++){
            int e = q.front();
            q.pop();
            q.push(e);
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << '>' << '\n';
}