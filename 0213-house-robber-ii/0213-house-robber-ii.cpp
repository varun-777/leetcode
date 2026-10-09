class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+2,0);
        vector<int>dp2(n+2,0);
        for(int i=2;i<n+1;i++){
            dp1[i] = max(nums[i-2]+dp1[i-2],dp1[i-1]);
        }
         for(int i=3;i<n+2;i++){
            dp2[i] = max(nums[i-2]+dp2[i-2],dp2[i-1]);
        }
        return max(dp1[n],dp2[n+1]);
    }
};