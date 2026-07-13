class RecentCounter {
private:
    queue<int> req;
public:
    RecentCounter() {
        req = queue<int>(); // 큐 초기화
    }
    
    int ping(int t) {
        req.push(t); // 큐에 현재 요청 넣기
        while(req.front() < t-3000) req.pop(); // 3000ms 보다 오래된 요청들은 삭제

        return req.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */