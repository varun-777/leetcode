class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0) return {1};
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        vector<int>ans;
         for(int i=0;i<=n;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                if(j-1>=0) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j] = 1;
                if(i==n)
                temp.push_back(dp[i][j]);
            }
            ans = temp;
         }
         return ans;
    }
};