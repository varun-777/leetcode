class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};