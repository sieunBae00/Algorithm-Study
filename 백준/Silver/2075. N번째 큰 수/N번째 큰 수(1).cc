#include<iostream>

using namespace std;

#include <queue>

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

    int N;

    cin >> N;

    

    for(int i=0; i<N; i++){

        for(int j=0; j<N; j++){

            int n;

            cin >> n;

            

            pq.push(n);

            if(pq.size() > N) pq.pop();

        } 

    }

    

    cout << pq.top() << '\n';

    

    return 0;

}
