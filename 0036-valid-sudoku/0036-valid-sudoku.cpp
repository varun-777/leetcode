class Solution {
public:
    bool isvalid(int i, int j, char c, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c&&k!=j)
                return false;
        }
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == c&&k!=i)
                return false;
        }
        int sr, sc;
        sr = (i / 3) * 3, sc = (j / 3) * 3;
        for (int x = sr; x < sr + 3; x++) {
            for (int y = sc; y < sc + 3; y++) {
                if (board[x][y] == c&&x!=i&&y!=j)
                    return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isvalid(i, j, board[i][j], board))
                        return false;
                }
            }
        }
        return true;
    }
};