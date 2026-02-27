#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> V;
    int ans = 0;
    
    int n;
    cin >> n;
    
    V.resize(n);
    
    for(int i=0; i<n; i++){
        cin >> V[i];
    }
    
    sort(V.begin(), V.end()); // 정렬
    
    int x;
    cin >> x;
    
    int i = 0;
    int j = n-1;
    int curr;
    
    while(i < j){
        curr = V[i] + V[j];
        
        if(curr == x){
            ans++;
            i++;
            j--;
        }
        else if(curr < x){
            i++;
        }
        else{
            j--;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}