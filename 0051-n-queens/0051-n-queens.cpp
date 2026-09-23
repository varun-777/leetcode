class Solution {
public:

    bool safe(int r,int c,vector<int>board){
        for(int i=0;i<r;i++){
            if(board[i]==c||abs(board[i]-c)==abs(r-i))
            return false;
        }
        return true;
    } 
    
    void solve(int r,int n,vector<int>board){
        if(r==n){
            vector<string>temp(n,string(n,'.'));
            for(int i=0;i<n;i++){
                temp[i][board[i]]='Q';
            }
            ans.push_back(temp);
            return;
        }
        for(int c=0;c<n;c++){
            if(safe(r,c,board)){
                board[r]=c;
                solve(r+1,n,board);
            }
        }
    }
    vector<vector<string>>ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<int>board(n,-1);
        solve(0,n,board);
        return ans;
    }
};