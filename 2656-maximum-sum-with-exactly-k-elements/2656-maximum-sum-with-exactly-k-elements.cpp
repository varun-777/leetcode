class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxx = *max_element(nums.begin(),nums.end());
        int n = k-1;
        n = (n+1)*n/2;
        return maxx*k+n;
    }
};