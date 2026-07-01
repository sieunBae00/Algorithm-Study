class Solution {
    int count = 0; // 정답 개수

    // 현재 위치에 퀸을 놔도 안전한지 검사
    bool isSafe(int row, int col, int n, vector<vector<bool>>& board) {
        // 위쪽 열 검사
        for (int i = 0; i < row; i++) {
            if (board[i][col]) return false;
        }

        // 오른쪽 아래(\) 방향 대각선 검사
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j]) return false;
        }

        // 왼쪽 아래(/) 대각선 검사
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j]) return false;
        }

        return true; // 무사히 통과했다면 안전함!
    }

    void backtrack(int row, int n, vector<vector<bool>>& board) {
        // Base Case: 끝 줄까지 퀸을 무사히 다 놨을 경우
        if (row == n) {
            count++;
            return;
        }

        // 현재 줄(row)에서 0번 ~ n-1번 (col) 까지 다 확인
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n, board)) { // 안전한지 확인
                // 퀸 배치하기
                board[row][col] = true;
                
                // 다음 줄(row + 1) 탐색하기
                backtrack(row + 1, n, board);
                
                // 퀸 회수하기
                board[row][col] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        // N x N 체스판 생성, false 로 초기화
        vector<vector<bool>> board(n, vector<bool>(n, false));

        // 0번째 줄부터 탐색
        backtrack(0, n, board);

        return count;
    }
};
