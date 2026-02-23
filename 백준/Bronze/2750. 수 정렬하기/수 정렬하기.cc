#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> V;

    int N;
    cin >> N;
    
    V.resize(N);
    
    for(int i=0; i<N; i++){
        cin >> V[i];
    }
    
    sort(V.begin(), V.end());
    
    for(int i=0; i<N; i++){
        cout << V[i] << '\n';
    }
    
    return 0;
}