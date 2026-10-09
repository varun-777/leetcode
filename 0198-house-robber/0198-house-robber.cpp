class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp(n+2,0);
        for(int i=2;i<n+2;i++){
            dp[i] = max(nums[i-2]+dp[i-2],dp[i-1]);
        }
        return dp[n+1];
    }
};