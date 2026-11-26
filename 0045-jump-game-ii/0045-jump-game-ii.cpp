class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int steps = 0;
        int reach = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            reach = max(reach, i + nums[i]);

            if (i == currentEnd) {
                steps++;
                currentEnd = reach;
            }
        }

        return steps;
    }
};