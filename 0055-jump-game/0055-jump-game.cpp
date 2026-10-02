class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n,false);
        dp[n-1] = true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0) {
                continue;
            }
            int reach = i+nums[i];
            int flag = 0;
            for(int j=i+1;j<=reach;j++){
                if(j<n&&dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};