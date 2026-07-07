class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // 배열 정렬

        for(int i=0; i<nums.size(); i++){
            int left(i+1), right(nums.size()-1); // left 를 0부터 다시 시작할 필요 x. 이미 이전에 등장했던 경우의 수임.
            if(i>0 && nums[i] == nums[i-1]) continue; // 고정되는 수가 똑같을 경우 -> 이미 모든 경우의 수를 찾았으므로 continue.
            
            while(left < right){                
                if(nums[left] + nums[right] == -nums[i]){ // 두 수가 고정된 수와 더해졌을 때 0인지를 검사
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // 정답을 찾은 후, 다음 숫자가 똑같으면 -> 이미 경우의 수에 포함되었으므로 계속 이동.
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] < -nums[i]){ // 합이 원하는 값보다 작을 경우
                    left++; // 더 큰 수가 필요하므로 left 를 증가
                }
                else{ // 합이 원하는 값보다 큰 경우
                    right--; // 더 작은 수가 필요하므로 right 를 감소
                }
            }
        }

        return ans;
    }
};