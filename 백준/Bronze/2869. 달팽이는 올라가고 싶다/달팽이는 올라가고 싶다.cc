#include <iostream>
using namespace std;
#include <cmath>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B, V;
    cin >> A >> B >> V;
    
    int day = A-B;
    int goal = V-A;
    
    int ans = ceil((double)goal / day);
    
    cout << ans + 1 << '\n';
    
   return 0;
}