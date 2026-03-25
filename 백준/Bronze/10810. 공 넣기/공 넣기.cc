#include <iostream>
using namespace std;
#include <vector>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> basket;
    
    int N, M;
    cin >> N >> M;
    
    basket.resize(N+1, 0); // 1~N번 바구니
    
    for(int l=0; l<M; l++){
        int i, j, k;
        cin >> i >> j >> k;
        
        for(int m = i; m <= j; m++){
            basket[m] = k;
        }
    }
    
    for(int i = 1; i<basket.size(); i++) {
        cout << basket[i] << " ";
    }
    
   return 0;
}