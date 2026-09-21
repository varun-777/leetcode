class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& temp, vector<bool> vis, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                temp.push_back(nums[i]);
                solve(temp, vis, nums);
                temp.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size(), idx = 0;
        vector<int> temp;
        vector<bool> vis(n, false);
        solve(temp, vis, nums);
        return ans;
    }
};