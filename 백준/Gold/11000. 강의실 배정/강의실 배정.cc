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

        pq.push({S, T}); // 수업 시간을 큐에 저장
    }
    
    while(!pq.empty()){
        p time = pq.top();

        if(room.empty()){
            room.push(time.second); // '교실 큐' 가 비었으면 일단 push()
            pq.pop(); // 수업 시간 큐에서 제거
            continue;
        }

        if(room.top() > time.first){ // 만약 시간이 겹쳐서 교실에 들어갈 수 없다면
            room.push(time.second); // 교실을 추가하고 해당 시간을 선점한다.
            pq.pop(); 
        }
        else{ // 만약 교실에 들어갈 수 있다면
            int endtime = room.top(); 
            room.pop();
            endtime = time.second; // 끝나는 시간을 현재 수업으로 바꾼다.
            room.push(endtime);
            pq.pop();
        }
    }
    
    cout << room.size() << '\n'; // '교실 큐'의 크기 (=교실 수) 를 출력한다.

    return 0;
}

