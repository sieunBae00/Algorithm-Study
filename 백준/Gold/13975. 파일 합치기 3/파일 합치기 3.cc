#include<iostream>

using namespace std;

#include <queue>

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int T;

    cin >> T;

    

    for(int i=0; i<T; i++){

        priority_queue<long long, vector<long long>, greater<long long>> pq; // 최소힙

        long long ans =0;

    

        int K;

        cin >> K;

        

        for(int j=0; j<K; j++){

            int p;

            cin >> p;

            pq.push(p);

        }

        

        while(pq.size() > 1){

            long long p1 = pq.top();

            pq.pop();

            long long p2 = pq.top();

            pq.pop();

            

            pq.push(p1+p2);

            ans += p1 + p2;

        }

        // 하나의 파일이 만들어진 상태 (힙에 남아있는 파일 1개)

        

        cout << ans << '\n';

    }

    

    return 0;

}