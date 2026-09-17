class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int prev = INT_MIN;
        int j,k;
        for(int i=0;i<n-2;i++){
            if(nums[i]==prev) continue;
            j = i + 1 , k = n - 1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0) 
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j]==nums[j+1]) j++;
                    while(j<k&&nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(sum<0) j++;
                else
                k--;
            }
            prev = nums[i];
        }
        return ans;
    }
};