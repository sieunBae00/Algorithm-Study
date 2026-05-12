class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left(0), right(height.size()-1);

        while(left < right){
            int water = min(height[left], height[right]) * (right-left);
            if(water > max_water) max_water = water;

            (height[left] < height[right]) ? left++ : right--; // 둘 중 더 짧은 쪽을 안쪽으로 한 칸 이동시키기
        }

        return max_water;
    }
};