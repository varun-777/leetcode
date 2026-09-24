class Solution {
public:
    bool solve(int i,int j,string temp,vector<vector<bool>>&vis,string s,vector<vector<char>>&board){
        int n = board.size();
        int m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
            return false;

        if (board[i][j] != s[temp.size()])
            return false;

        temp += board[i][j];

        if (temp.size() == s.size())
            return true;

        vis[i][j] = true;

        bool left = solve(i, j - 1, temp, vis, s, board);
        bool right = solve(i, j + 1, temp, vis, s, board);
        bool up = solve(i - 1, j, temp, vis, s, board);
        bool down = solve(i + 1, j, temp, vis, s, board);

        vis[i][j] = false;

        return left || right || up || down;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),i=0,j=0,m=board[0].size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    p.push_back({i,j});
                }
            }
        }
       
        for(auto it:p){
             vector<vector<bool>>vis(n,vector<bool>(m,false));
        if(solve(it.first,it.second,"",vis,word,board)) return true;
        }
        return false;
    }
};