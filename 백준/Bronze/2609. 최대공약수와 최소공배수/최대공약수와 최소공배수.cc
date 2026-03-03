#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    
    int c = a%b;
    return gcd(b, c);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n1, n2;
    cin >> n1 >> n2;
    
    // 최대공약수
    int g = gcd(n1, n2);
    
    // 최소공배수
    int l = n1*n2 / g;
    
    cout << g << '\n';
    cout << l << '\n';
    
    return 0;
}