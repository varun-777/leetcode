class Solution {
public:
    bool isvalid(int i, int j, char c, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c)
                return false;
        }
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == c)
                return false;
        }
        int sr, sc;
        sr = (i / 3) * 3, sc = (j / 3) * 3;
        for (int x = sr; x < sr+3; x++) {
            for (int y = sc; y < sc+3; y++) {
                if (board[x][y] == c)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isvalid(i, j, k, board)) {
                            board[i][j] = k;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};