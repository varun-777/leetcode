class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0, r = 0, sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        int target = sum - x, ans = INT_MIN;
        if (sum < x)
            return -1;
        sum = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > target) {
                sum -= nums[l];
                l++;
            }
            if (sum == target) {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        if (ans == INT_MIN)
            return -1;
        return n - ans;
    }
};