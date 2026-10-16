class Solution {
public:

    int solve(int i,vector<int>&piles,int m,vector<vector<int>>&dp){
        if(i>=piles.size()) return 0;

        if(dp[i][m]!=-1) return dp[i][m];

        int ans = INT_MIN,tot = 0;
        for(int j=0;j<2*m;j++){
            if(i+j<piles.size()) tot+=piles[i+j];
            ans = max(ans,tot - solve(i+j+1,piles,max(m,j+1),dp));
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(2*n,-1));
        int ans =  solve(0,piles,1,dp);
        int sum = accumulate(piles.begin(),piles.end(),0);
        return (sum+ans)/2;
    }
};