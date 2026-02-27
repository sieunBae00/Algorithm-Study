#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> V;
    
    int N;
    cin >> N;
    
    V.resize(N+1);
    
    for(int i=1; i<=N; i++){
        cin >> V[i];
    }
    
    sort(V.begin(), V.end()); // 정렬
    
    int med = V.size() / 2; // 소수점 버림, 자동으로 더 작은 쪽이 됨
    
    cout << V[med] << '\n';
    
    return 0;
}