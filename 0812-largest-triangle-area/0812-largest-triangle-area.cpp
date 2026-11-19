class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& nums) {
        int n = nums.size();
        double maxarea = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    int x1 = nums[i][0],y1 = nums[i][1];
                    int x2 = nums[j][0],y2 = nums[j][1];
                    int x3 = nums[k][0],y3 = nums[k][1];
                     double area = 0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
                     maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};