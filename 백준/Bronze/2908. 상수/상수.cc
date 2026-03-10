#include<iostream>
using namespace std;
#include <cmath>

int solve(int num){
    int n1 = num % 10;
    int n23 = num / 10;
        
    int n2 = n23 % 10;
    int n3 = n23 / 10;
    
    return n1*100 + n2*10 + n3;
}


int main(){
    int A, B;
    cin >> A >> B;
    
    int AA = solve(A);
    int BB = solve(B);
    
    cout << max(AA, BB) << '\n';
    
    return 0;
}