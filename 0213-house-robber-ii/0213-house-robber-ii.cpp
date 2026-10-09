class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+2,0);
        for(int i=2;i<n+1;i++){
            dp[i] = max(nums[i-2]+dp[i-2],dp[i-1]);
        }
        int first = dp[n];
        dp.assign(n+2,0);
         for(int i=3;i<n+2;i++){
            dp[i] = max(nums[i-2]+dp[i-2],dp[i-1]);
        }
        return max(first,dp[n+1]);
    }
};