class Solution {
private:
    // 재귀함수의 매개변수 간소화: 클래스 멤버 변수로 빼기
    int tar_k;
    int tar_n;
    vector<vector<int>> ans;
    
public:
    void BackTrack(int st_num, vector<int>& path, int sum){
        if(sum > tar_n) return; // 현재 sum 이 n 을 초과 -> 가망 없음.
        if(path.size() == tar_k){ // 바구니가 다 찬 경우
            if(sum == tar_n) ans.push_back(path); // n 에 들어맞으면 -> 정답 배열에 추가
            return; // 더 담을 필요 없으므로 돌아가기.
        }

        for(int i=st_num; i<10; i++){ // 본질은 brute-force.
            path.push_back(i);
            BackTrack(i+1, path, sum+i); // 파라미터 넘겨주는 방식 주의.
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        tar_k = k;
        tar_n = n;
        
        vector<int> path;
        BackTrack(1, path, 0);

        return ans;
    }
};