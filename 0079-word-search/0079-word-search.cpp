class Solution {
public:
    int n, m;
    vector<vector<int>> direction{{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool helper(int i, int j, int idx, vector<vector<char>>& board, string& word) {
        // Success case: The entire word has been matched
        if (idx == word.size()) {
            return true;
        }

        // Out of bounds check
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }

        // Mismatch or already visited check
        if (board[i][j] != word[idx] || board[i][j] == '$') {
            return false;
        }

        // Backtracking: Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore all 4 neighbors
        for (auto& dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if (helper(new_i, new_j, idx + 1, board, word))
                return true;
        }

        // Backtracking: Restore original character
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();     // rows
        m = board[0].size();  // columns

        // --- OPTIMIZATION TO PREVENT TLE ---
        int board_counts[128] = {0};
        int word_counts[128] = {0};
        
        // 1. Count frequencies on the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board_counts[board[i][j]]++;
            }
        }
        
        // 2. Count frequencies required by the word
        for (char c : word) {
            word_counts[c]++;
        }
        
        // Pruning Check 1: If the board lacks enough characters, return false immediately
        for (int i = 0; i < 128; i++) {
            if (board_counts[i] < word_counts[i]) {
                return false;
            }
        }
        
        // Pruning Check 2: Word Reversal Trick
        // If the tail character is rarer than the head character, reverse the word 
        // to minimize the backtracking branches right from the start.
        if (board_counts[word.back()] < board_counts[word.front()]) {
            reverse(word.begin(), word.end());
        }
        // ------------------------------------

        // Main search loops
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && helper(i, j, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};