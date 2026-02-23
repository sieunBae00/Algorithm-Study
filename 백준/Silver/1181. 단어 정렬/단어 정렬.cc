// 1181 단어정렬

#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

bool judge(string a, string b){
    if(a.length() < b.length()){
        return true;
    }
    else if(a.length() > b.length()){
        return false;
    }
    else{
        if(a < b) return true;
        else return false; // a == b 일 경우에 대한 처리를 따로 하지 않음.
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> V;

    int N;
    cin >> N;
    
    V.resize(N);
    
    for(int i=0; i<N; i++){
        cin >> V[i];
    }
    
    sort(V.begin(), V.end(), judge); // sort() 는 상상 이상으로 똑똑하다! 직접 매개변수를 넣어 주지 않아도, sort() 가 알아서 배열(V) 에서 두 개씩 꺼내서 judge() 로 넘겨 준다.
    
    V.erase(unique(V.begin(), V.end()), V.end()); // 중복되는 원소를 맨 뒤로 밀어서 삭제
    
    for(int i=0; i<V.size(); i++){
        cout << V[i] << '\n';
    }
    
    return 0;
}