class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            string s = to_string(temp);
            int sum = 0;
            for (int j = 0; j < s.size(); j++) {
                sum += (s[j] - '0');
            }
            if (sum == i)
                return i;
        }
        return -1;
    }
};