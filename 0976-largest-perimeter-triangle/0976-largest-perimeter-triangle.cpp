class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();
        int a,b,c;
        for(int i=0;i<n-2;i++){
           a = nums[i];
           b = nums[i+1];
           c = nums[i+2];
           if(b+c>a) return a+b+c;
        }
        return 0;
    }
};