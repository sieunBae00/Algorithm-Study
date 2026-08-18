class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.push_back(asteroids[0]); // 첫 원소를 정답 배열에 넣은 후 시작

        for(int i=1; i<asteroids.size(); i++){
            if(asteroids[i] > 0) ans.push_back(asteroids[i]); // 양수일 경우: 정답 배열에 추가
            else{ //음수일 경우: 정답 배열의 마지막 원소와 비교
                while(1){
                    if(ans.size() == 0){
                        ans.push_back(asteroids[i]);
                        break;
                    }
                    if(ans.back() > 0){ // 정답 배열의 마지막 원소가 양수일 경우
                        if(ans.back() + asteroids[i] == 0){ // 같은 크기 -> 둘 다 사라짐
                        ans.pop_back();
                        break;
                        }
                        else if(ans.back() + asteroids[i] > 0) break; // 졌다 -> 없어짐
                        else{ // 이겼다 -> 정답 배열의 마지막 원소가 사라지고 다음 원소와 비교
                            ans.pop_back();
                            if(ans.size() == 0) {
                                ans.push_back(asteroids[i]);
                                break;
                            }
                        }
                    }
                    else{ // 정답 배열의 마지막 원소가 음수일 경우
                        ans.push_back(asteroids[i]);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};