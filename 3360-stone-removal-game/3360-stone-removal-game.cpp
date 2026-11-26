class Solution {
public:
    bool canAliceWin(int n) {
        vector<bool>dp(51,false);
        for(int i=10;i<=18;i++) dp[i] = true;
        for(int i=27;i<34;i++) dp[i] = true;
        for(int i=40;i<=44;i++) dp[i] = true;
        dp[49] = dp[50] = true;
        return dp[n];
    }
};