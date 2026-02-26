#include<iostream>
using namespace std;
#include <vector>
#include <queue>

int main(){
    typedef pair<int, int> p;
    priority_queue<p, vector<p>, greater<p>> pq; // 수업 시간
    priority_queue<int, vector<int>, greater<int>> room; // 현재 교실들

    int N;
    cin >> N;
    
    for(int i=0; i<N; i++){
        int S, T;
        cin >> S >> T;

        pq.push({S, T});
    }
    
    while(!pq.empty()){
        p time = pq.top();

        if(room.empty()){
            room.push(time.second);
            pq.pop();
            continue;
        }

        if(room.top() > time.first){ // 🤦‍♂️🤦‍♂️ 아... 만약에 교실을 꺼냈는데 못 들어가면? (어제 보석도둑 과 같은상황.) 반대로 생각해보기~~
        // 못 들어가면 교실을 새로 만들어야지 !! 어차피 끝이 가장 적은 시간대의 교실을 뺀 건데, 거길 못 들어가면 다른 곳도 못 들어가지 !!
            room.push(time.second);
            pq.pop();
        }
        else{
            int endtime = room.top();
            room.pop();
            endtime = time.second;
            room.push(endtime);
            pq.pop();
        }
    }
    
    cout << room.size() << '\n';

    return 0;
}
