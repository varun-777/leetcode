class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>>temp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int maxx1 = INT_MIN;
                int maxx2 = INT_MIN;
                for(int k = 0;k<n;k++) maxx1 = max(maxx1,nums[i][k]);
                for(int k = 0;k<n;k++) maxx2 = max(maxx2,nums[k][j]);
                temp[i][j] = min(maxx1,maxx2);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<temp[i][j]<<" ";
                ans+=(temp[i][j] - nums[i][j]);
            }
            cout<<"\n";
        }
        return ans;
    }
};