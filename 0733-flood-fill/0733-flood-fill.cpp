class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image; // 칠하려는 색이 원래 색과 같다면 그냥 return.

        int initialColor = image[sr][sc]; // 시작점의 처음 색깔

        image[sr][sc] = color; // 새로운 색으로 칠하기

        // 상(-1, 0), 하(1, 0), 좌(0, -1), 우(0, 1)
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // 상하좌우 4방향 모두 탐색
        for (int i = 0; i < 4; i++) {
            int next_r = sr + dr[i];
            int next_c = sc + dc[i];
    
            // 유효 범위인지 검사
            if(0 <= next_r && next_r < image.size() && 0 <= next_c && next_c < image[0].size()){
                if(image[next_r][next_c] == initialColor) floodFill(image, next_r, next_c, color);
            }
        }
        return image;
    }
};