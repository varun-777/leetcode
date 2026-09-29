class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<vector<int>>ans;
        dp[0][0] = 1;
        ans.push_back({dp[0][0]});
         for(int i=1;i<n;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                if(j-1>=0) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j] = 1;
                temp.push_back(dp[i][j]);
            }
            ans.push_back(temp);
         }
         return ans;
    }
};