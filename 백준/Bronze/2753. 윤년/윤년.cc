#include <iostream>
using namespace std;

int main() {
    bool ans = false;

    int year;
    cin >> year;
    
    if(year % 400 == 0) ans = true;
    else if(year % 100 != 0){
        if(year % 4 == 0) ans = true;
    }
    
    cout << (int)ans << '\n';
   
   return 0;
}