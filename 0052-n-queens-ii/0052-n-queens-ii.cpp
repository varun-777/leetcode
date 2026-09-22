class Solution {
public:

    int count = 0;

    bool place(int row,int col,vector<int>&board){
        for(int i=0;i<row;i++){
            if(board[i]==col||abs(board[i]-col)==abs(i-row)) return false;
        }
        return true;
    }
    
    void solve(int row,int n,vector<int>&board){
        if(row == n){
            count++;
            return;
        }
        for(int col = 0;col < n; col++){
            if(place(row,col,board)){
                board[row] = col;
                row++;
                solve(row,n,board);
                row--;
                board[row] = -1;
            }
        }
    }

    int totalNQueens(int n) {
        vector<int>board(n,-1);
        solve(0,n,board);
        return count;
    }
};