class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, int target, int n,
               vector<int>temp) {
        
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx == n||target<0) {
            return;
        }
        for(int i=idx;i<n;i++){
            if(i>idx&&nums[i]==nums[i-1]) continue;

            if(nums[i]>target) break;

            temp.push_back(nums[i]);
            solve(i+1,nums,target-nums[i],n,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(0, nums, target, n, {});
        return ans;
    }
};